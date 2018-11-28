/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "timer.h"
#include "eeconfig.h"

#define _CGX    0
#define _QWERTY 1
#define _SHIFT  2
#define _NUM    3
#define _NUM_SHIFT 4
#define _SYM    5
#define _MOUSE  6

#define PERMISSIVE_HOLD

enum custom_keycodes {
  CGX = SAFE_RANGE,
  QWERTY,
  MOD_SHIFT,
  NUM_SHIFT,
};

static uint16_t key_timer;

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_VOLD:
      if (record->event.pressed) {
        key_timer = timer_read();
      } else {
        if (timer_elapsed(key_timer) > 150) {
          register_code(KC_MUTE);
          unregister_code(KC_MUTE);
        }
      }
      break;
    case CGX:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_CGX);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
      case MOD_SHIFT:
      if (record->event.pressed) {
          register_code(KC_LSFT);
          layer_on(_SHIFT);
      } else {
          layer_off(_SHIFT);
          layer_off(_NUM_SHIFT);
          unregister_code(KC_LSFT);
      }
      return false;
      break;
    case NUM_SHIFT:
      if (record->event.pressed) {
          register_code(KC_LSFT);
          layer_on(_NUM_SHIFT);
      } else {
          layer_off(_NUM_SHIFT);
          unregister_code(KC_LSFT);
      }
      return false;
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* CGx
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   W  |   L  |   R  |   B  |   `  |   |  |   Y  |   I  |   U  |   V  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   S  |   N  |   T  |   D  |   ,  |   .  |   A  |   E  |   O  |   H  |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Alt  |   J  |   P  |   C  |   K  |   Q  |   Z  |   M  |   F  |   G  |   X  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp | Win  | Del  | Esc  |Shift |Mouse |Number|Space | Alt  | VolD | VolU |Symbol|
 * `-----------------------------------------------------------------------------------'
 */

  [_CGX] = LAYOUT_ortho_4x12( \
  KC_TAB  , KC_W   , KC_L  , KC_R  , KC_B     , KC_GRV    , KC_PIPE , KC_Y  , KC_I   , KC_U   , KC_V   , KC_QUOT, \
  KC_LCTRL, KC_S   , KC_N  , KC_T  , KC_D     , KC_COMM   , KC_DOT  , KC_A  , KC_E   , KC_O   , KC_H   , KC_SCLN, \
  KC_LALT , KC_J   , KC_P  , KC_C  , KC_K     , KC_Q      , KC_Z    , KC_M  , KC_F   , KC_G   , KC_X   , KC_ENT , \
  KC_BSPC , KC_LGUI, KC_DEL, LCTL_T(KC_ESC), LSFT_T(KC_BSPC), TT(_MOUSE), TT(_NUM), LT(_NUM, KC_SPC), KC_LALT, KC_VOLD, KC_VOLU, TT(_SYM) \
),

/* Shift
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   ?  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   &  |   *  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SHIFT] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, KC_QUES, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_AMPR, KC_ASTR, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |      |      |   <  |   >  |      |      |      |   7  |   8  |   9  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   (  |   [  |   ]  |   )  |      |      |   4  |   5  |   6  |   0  |  %   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   ~  |   ^  |   =  |      |      |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_ortho_4x12( \
  _______, _______, KC_LABK, KC_RABK, _______, _______, _______,    KC_7,    KC_8,    KC_9, KC_MINS, _______,\
  _______, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, _______, _______,    KC_4,    KC_5,    KC_6,    KC_0, KC_PERC,\
  _______, KC_BSLS, KC_TILD, KC_CIRC,  KC_EQL, _______, _______,    KC_1,    KC_2,    KC_3, KC_SLSH, _______,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Num Shift
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |   (  |   )  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   {  |   }  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM_SHIFT] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      | CGx  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_ortho_4x12( \
  _______, KC_F1, KC_F2,  KC_F3,  KC_F4, _______, _______, _______, _______, _______, _______, CGX, \
  _______, KC_F5, KC_F6,  KC_F7,  KC_F8,  _______,  _______,     _______, _______, _______, _______, QWERTY, \
  _______, KC_F9, KC_F10, KC_F11, KC_F12, _______,  _______,     _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      | PgUp | Home |  Up  | End  |      |      |LClick| MUp  |RClick|ScrUp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | PgDn | Left | Down | Right|      |      |MLeft |MDown |MRight|ScrDn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Undo | Cut  | Copy | Paste|CapLoc|      | ScrL |MClick| ScrR |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_ortho_4x12( \
  _______, KC_PGUP   , KC_HOME   , KC_UP      ,   KC_END  , _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, \
  _______, KC_PGDN   , KC_LEFT   , KC_DOWN    , KC_RIGHT  , _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, \
  _______, LCTL(KC_Z), LCTL(KC_X),  LCTL(KC_C), LCTL(KC_V), KC_CAPS, _______, KC_WH_L, KC_BTN3, KC_WH_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  |Symbol|Space |Mouse |Number|Space | Del  | VolD | VolU |  Esc |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_BSPC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTL, KC_LGUI, KC_LALT, TT(_SYM), KC_SPC,  TT(_MOUSE),  TT(_NUM),  KC_SPC,   KC_DEL, KC_VOLD, KC_VOLU, KC_ESC \
)
};

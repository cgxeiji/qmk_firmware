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

#include "jj40.h"
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
 * | Tab  |   W  |   L  |   R  |   B  |   -  |   !  |   Y  |   I  |   U  |   V  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   S  |   N  |   T  |   D  |   ,  |   .  |   A  |   E  |   O  |   H  |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   J  |   P  |   C  |   K  |   Q  |   Z  |   M  |   F  |   G  |   X  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  |Symbol|Shift |Mouse |Number|Space | Del  | VolD | VolU |  Esc |
 * `-----------------------------------------------------------------------------------'
 */

  [_CGX] = KEYMAP( \
  KC_TAB,   KC_W,  KC_L,  KC_R,  KC_B,  KC_MINS,  KC_EXLM,  KC_Y,  KC_I,  KC_U,  KC_V,  KC_QUOT, \
  KC_BSPC,  KC_S,  KC_N,  KC_T,  KC_D,  KC_COMM,  KC_DOT,   KC_A,  KC_E,  KC_O,  KC_H,  KC_SCLN, \
  KC_LSHIFT,KC_J,  KC_P,  KC_C,  KC_K,  KC_Q,     KC_Z,     KC_M,  KC_F,  KC_G,  KC_X,  KC_ENT, \
  KC_LCTL,  KC_LGUI, KC_LALT, TT(_SYM), MOD_SHIFT, TT(_MOUSE), TT(_NUM), KC_SPC, KC_DEL, KC_VOLD, KC_VOLU, KC_ESC \
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
[_SHIFT] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, KC_QUES, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_AMPR, KC_ASTR, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |      |   `  |   ~  |   -  |   |  |   \  |   -  |   7  |   8  |   9  |   ,  |  %   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   !  |   <  |   >  |   =  |   ^  |   +  |   4  |   5  |   6  |   .  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   @  |   $  |   &  |   #  |      |   *  |   1  |   2  |   3  |   0  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |NuShft|      |      |      |      |      |      |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = KEYMAP( \
  _______, KC_GRV,  KC_TILD, KC_MINS, KC_BSLS, KC_PIPE, KC_MINS, KC_7, KC_8, KC_9, KC_COMM, KC_PERC, \
  _______, KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_CIRC, KC_PLUS, KC_4, KC_5, KC_6, KC_DOT,  KC_SLASH, \
  _______, KC_AT,   KC_DLR,  KC_AMPR, KC_HASH, _______, KC_ASTR, KC_1, KC_2, KC_3, KC_0,    KC_EQL, \
  _______, _______, _______, _______, NUM_SHIFT, _______, _______, _______, _______, _______, _______, KC_ENT \
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
[_NUM_SHIFT] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |   (  |   )  |      | CGx  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |   [  |   ]  |      |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |   {  |   }  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = KEYMAP( \
  _______, KC_F1, KC_F2,  KC_F3,  KC_F4, _______, _______, _______, KC_LPRN, KC_RPRN, _______, CGX, \
  _______, KC_F5, KC_F6,  KC_F7,  KC_F8,  _______,  _______,     _______, KC_LBRC, KC_RBRC, _______, QWERTY, \
  _______, KC_F9, KC_F10, KC_F11, KC_F12, _______,  _______,     _______, KC_LCBR, KC_RCBR, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      | PgUp | Home |  Up  | End  |      |      |LClick| MUp  |RClick|ScrUp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | PgDn | Left | Down | Right|      |      |MLeft |MDown |MRight|ScrDn |CtrlSh|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CapLoc| Undo | Cut  | Copy | Paste|      |      | ScrL |MClick| ScrR |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = KEYMAP( \
  _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,   _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, \
  _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, LCTL(KC_LSHIFT), \
  KC_CAPS, LCTL(KC_Z), LCTL(KC_X),  LCTL(KC_C), LCTL(KC_V), _______, _______, KC_WH_L, KC_BTN3, KC_WH_R, _______, KC_LSHIFT, \
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
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_BSPC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTL, KC_LGUI, KC_LALT, TT(_SYM), KC_SPC,  TT(_MOUSE),  TT(_NUM),  KC_SPC,   KC_DEL, KC_VOLD, KC_VOLU, KC_ESC \
)
};

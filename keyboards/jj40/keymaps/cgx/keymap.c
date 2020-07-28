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
#define _SHIFT  1
#define _QWERTY 2
#define _KANA   3
#define _NUM    4
#define _NUM_SHIFT 5
#define _SYM    6
#define _MOUSE  7


#define _KANA_N  17

#define _KANA_H 18
#define _KANA_B 19
#define _KANA_P 20

#define _KANA_S 21
#define _KANA_Z 22

#define _KANA_R 23

#define _KANA_T 24
#define _KANA_D 25

#define _KANA_K 26
#define _KANA_G 27

#define _KANA_M 28

#define _KANA_Y 29
#define _KANA_L 30

#define _KANA_W 31

#define PERMISSIVE_HOLD

enum custom_keycodes {
  CGX = SAFE_RANGE,
  QWERTY,
  MOD_SHIFT,
  NUM_SHIFT,

  KANA_KA,
  KANA_KI,
  KANA_KU,
  KANA_KE,
  KANA_KO,

  KANA_GA,
  KANA_GI,
  KANA_GU,
  KANA_GE,
  KANA_GO,

  KANA_SA,
  KANA_SI,
  KANA_SU,
  KANA_SE,
  KANA_SO,

  KANA_ZA,
  KANA_ZI,
  KANA_ZU,
  KANA_ZE,
  KANA_ZO,

  KANA_TA,
  KANA_TI,
  KANA_TU,
  KANA_TE,
  KANA_TO,

  KANA_DA,
  KANA_DI,
  KANA_DU,
  KANA_DE,
  KANA_DO,

  KANA_NA,
  KANA_NI,
  KANA_NU,
  KANA_NE,
  KANA_NO,

  KANA_NN,

  KANA_HA,
  KANA_HI,
  KANA_HU,
  KANA_HE,
  KANA_HO,

  KANA_BA,
  KANA_BI,
  KANA_BU,
  KANA_BE,
  KANA_BO,

  KANA_PA,
  KANA_PI,
  KANA_PU,
  KANA_PE,
  KANA_PO,

  KANA_MA,
  KANA_MI,
  KANA_MU,
  KANA_ME,
  KANA_MO,

  KANA_RA,
  KANA_RI,
  KANA_RU,
  KANA_RE,
  KANA_RO,

  KANA_YA,
  KANA_YU,
  KANA_YO,

  KANA_LA,
  KANA_LU,
  KANA_LO,

  KANA_WA,
  KANA_WO,
  KANA_XU,

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CGX:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_CGX);
      }
      return false;
      break;

    case KANA_KA:
      if (record->event.pressed) { SEND_STRING("ka"); }
      break;
    case KANA_KI:
      if (record->event.pressed) { SEND_STRING("ki"); }
      break;
    case KANA_KU:
      if (record->event.pressed) { SEND_STRING("ku"); }
      break;
    case KANA_KE:
      if (record->event.pressed) { SEND_STRING("ke"); }
      break;
    case KANA_KO:
      if (record->event.pressed) { SEND_STRING("ko"); }
      break;

    case KANA_GA:
      if (record->event.pressed) { SEND_STRING("ga"); }
      break;
    case KANA_GI:
      if (record->event.pressed) { SEND_STRING("gi"); }
      break;
    case KANA_GU:
      if (record->event.pressed) { SEND_STRING("gu"); }
      break;
    case KANA_GE:
      if (record->event.pressed) { SEND_STRING("ge"); }
      break;
    case KANA_GO:
      if (record->event.pressed) { SEND_STRING("go"); }
      break;

    case KANA_SA:
      if (record->event.pressed) { SEND_STRING("sa"); }
      break;
    case KANA_SI:
      if (record->event.pressed) { SEND_STRING("si"); }
      break;
    case KANA_SU:
      if (record->event.pressed) { SEND_STRING("su"); }
      break;
    case KANA_SE:
      if (record->event.pressed) { SEND_STRING("se"); }
      break;
    case KANA_SO:
      if (record->event.pressed) { SEND_STRING("so"); }
      break;

    case KANA_ZA:
      if (record->event.pressed) { SEND_STRING("za"); }
      break;
    case KANA_ZI:
      if (record->event.pressed) { SEND_STRING("zi"); }
      break;
    case KANA_ZU:
      if (record->event.pressed) { SEND_STRING("zu"); }
      break;
    case KANA_ZE:
      if (record->event.pressed) { SEND_STRING("ze"); }
      break;
    case KANA_ZO:
      if (record->event.pressed) { SEND_STRING("zo"); }
      break;

    case KANA_TA:
      if (record->event.pressed) { SEND_STRING("ta"); }
      break;
    case KANA_TI:
      if (record->event.pressed) { SEND_STRING("ti"); }
      break;
    case KANA_TU:
      if (record->event.pressed) { SEND_STRING("tu"); }
      break;
    case KANA_TE:
      if (record->event.pressed) { SEND_STRING("te"); }
      break;
    case KANA_TO:
      if (record->event.pressed) { SEND_STRING("to"); }
      break;

    case KANA_DA:
      if (record->event.pressed) { SEND_STRING("da"); }
      break;
    case KANA_DI:
      if (record->event.pressed) { SEND_STRING("di"); }
      break;
    case KANA_DU:
      if (record->event.pressed) { SEND_STRING("du"); }
      break;
    case KANA_DE:
      if (record->event.pressed) { SEND_STRING("de"); }
      break;
    case KANA_DO:
      if (record->event.pressed) { SEND_STRING("do"); }
      break;

    case KANA_NA:
      if (record->event.pressed) { SEND_STRING("na"); }
      break;
    case KANA_NI:
      if (record->event.pressed) { SEND_STRING("ni"); }
      break;
    case KANA_NU:
      if (record->event.pressed) { SEND_STRING("nu"); }
      break;
    case KANA_NE:
      if (record->event.pressed) { SEND_STRING("ne"); }
      break;
    case KANA_NO:
      if (record->event.pressed) { SEND_STRING("no"); }
      break;
    case KANA_NN:
      if (record->event.pressed) { SEND_STRING("nn"); }
      break;

    case KANA_HA:
      if (record->event.pressed) { SEND_STRING("ha"); }
      break;
    case KANA_HI:
      if (record->event.pressed) { SEND_STRING("hi"); }
      break;
    case KANA_HU:
      if (record->event.pressed) { SEND_STRING("hu"); }
      break;
    case KANA_HE:
      if (record->event.pressed) { SEND_STRING("he"); }
      break;
    case KANA_HO:
      if (record->event.pressed) { SEND_STRING("ho"); }
      break;

    case KANA_BA:
      if (record->event.pressed) { SEND_STRING("ba"); }
      break;
    case KANA_BI:
      if (record->event.pressed) { SEND_STRING("bi"); }
      break;
    case KANA_BU:
      if (record->event.pressed) { SEND_STRING("bu"); }
      break;
    case KANA_BE:
      if (record->event.pressed) { SEND_STRING("be"); }
      break;
    case KANA_BO:
      if (record->event.pressed) { SEND_STRING("bo"); }
      break;

    case KANA_PA:
      if (record->event.pressed) { SEND_STRING("pa"); }
      break;
    case KANA_PI:
      if (record->event.pressed) { SEND_STRING("pi"); }
      break;
    case KANA_PU:
      if (record->event.pressed) { SEND_STRING("pu"); }
      break;
    case KANA_PE:
      if (record->event.pressed) { SEND_STRING("pe"); }
      break;
    case KANA_PO:
      if (record->event.pressed) { SEND_STRING("po"); }
      break;

    case KANA_MA:
      if (record->event.pressed) { SEND_STRING("ma"); }
      break;
    case KANA_MI:
      if (record->event.pressed) { SEND_STRING("mi"); }
      break;
    case KANA_MU:
      if (record->event.pressed) { SEND_STRING("mu"); }
      break;
    case KANA_ME:
      if (record->event.pressed) { SEND_STRING("me"); }
      break;
    case KANA_MO:
      if (record->event.pressed) { SEND_STRING("mo"); }
      break;

    case KANA_RA:
      if (record->event.pressed) { SEND_STRING("ra"); }
      break;
    case KANA_RI:
      if (record->event.pressed) { SEND_STRING("ri"); }
      break;
    case KANA_RU:
      if (record->event.pressed) { SEND_STRING("ru"); }
      break;
    case KANA_RE:
      if (record->event.pressed) { SEND_STRING("re"); }
      break;
    case KANA_RO:
      if (record->event.pressed) { SEND_STRING("ro"); }
      break;

    case KANA_YA:
      if (record->event.pressed) { SEND_STRING("ya"); }
      break;
    case KANA_YU:
      if (record->event.pressed) { SEND_STRING("yu"); }
      break;
    case KANA_YO:
      if (record->event.pressed) { SEND_STRING("yo"); }
      break;

    case KANA_LA:
      if (record->event.pressed) { SEND_STRING("lya"); }
      break;
    case KANA_LU:
      if (record->event.pressed) { SEND_STRING("lyu"); }
      break;
    case KANA_LO:
      if (record->event.pressed) { SEND_STRING("lyo"); }
      break;

    case KANA_WA:
      if (record->event.pressed) { SEND_STRING("wa"); }
      break;
    case KANA_WO:
      if (record->event.pressed) { SEND_STRING("wo"); }
      break;
    case KANA_XU:
      if (record->event.pressed) { SEND_STRING("ltu"); }
      break;

    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case MOD_SHIFT:
      if (record->event.pressed) {
          layer_on(_SHIFT);
      } else {
          layer_off(_SHIFT);
          //layer_off(_NUM_SHIFT);
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
 * | Tab  |   W  |   L  |   R  |   B  |   `  |   _  |   Y  |   I  |   U  |   V  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   S  |   N  |   T  |   D  |   ,  |   .  |   A  |   E  |   O  |   H  |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GUI  |   J  |   P  |   C  |   K  |   Q  |   Z  |   M  |   F  |   G  |   X  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Alt  | KANA | Del  | Esc  |Shift |Mouse |Number|Space | GUI  | VolD | VolU |Symbol|
 * `-----------------------------------------------------------------------------------'
 */

  [_CGX] = LAYOUT_ortho_4x12( \
  KC_TAB  , KC_W   , KC_L  , KC_R  , KC_B     , KC_GRV    , KC_UNDS , KC_Y  , KC_I   , KC_U   , KC_V   , KC_QUOT, \
  KC_LCTRL, KC_S   , KC_N  , KC_T  , KC_D     , KC_COMM   , KC_DOT  , KC_A  , KC_E   , KC_O   , KC_H   , KC_SCLN, \
  KC_LGUI , KC_J   , KC_P  , KC_C  , KC_K     , KC_Q      , KC_Z    , KC_M  , KC_F   , KC_G   , KC_X   , KC_ENT , \
  KC_LALT , TG(_KANA), KC_DEL, LCTL_T(KC_ESC), LSFT_T(KC_BSPC), TT(_MOUSE), TT(_NUM), KC_SPC, KC_LGUI, KC_VOLD, KC_VOLU, TT(_SYM) \
),

/* Shift
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   ?  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   &  |   _  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SHIFT] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, KC_QUES, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_AMPR, KC_UNDS, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |      |   {  |   <  |   >  |   }  |      |      |   7  |   8  |   9  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   (  |   [  |   ]  |   )  |      |      |   4  |   5  |   6  |   0  |  %   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   ~  |   +  |   =  |      |      |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_ortho_4x12( \
  _______, KC_LCBR, KC_LABK, KC_RABK, KC_RCBR, _______, _______,    KC_7,    KC_8,    KC_9, KC_MINS, _______,\
  _______, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, _______, _______,    KC_4,    KC_5,    KC_6,    KC_0, KC_PERC,\
  _______, KC_BSLS, KC_TILD, KC_PLUS,  KC_EQL, _______, _______,    KC_1,    KC_2,    KC_3, KC_SLSH, _______,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Num Shift
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |   (  |   )  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   [  |   ]  |      |      |
 * |-----+------+------+------+------+------+------+------+------+------+------+------|
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
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, _______, _______, _______, _______, CGX    , \
  _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, _______, _______, _______, _______, _______, QWERTY , \
  _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Kana Input
 * ,-----------------------------------------------------------------------------------.
 * |      |  W   |  Y   |  R   |      |      |      |      |  I   |  U   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  S   |  N   |  T   |  H   |      |      |  A   |  E   |  O   |  X   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  M   |  K   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_KANA] = LAYOUT_ortho_4x12( \
  _______, MO(_KANA_W), MO(_KANA_Y), MO(_KANA_R), MO(_KANA_P), _______, _______, _______, _______, _______, _______, _______, \
  _______, MO(_KANA_S), MO(_KANA_N), MO(_KANA_T), MO(_KANA_H), _______, _______, _______, _______, _______, _______, _______, \
  _______, _______    , _______    , MO(_KANA_M), MO(_KANA_K), _______, _______, _______, _______, _______, _______, _______, \
  _______, _______    , _______    , _______    , _______    , _______, _______, _______, _______, _______, _______, _______ \
),
/*
[_S_KANA] = LAYOUT_ortho_4x12( \
  _______, _______    , MO(_KANA_L), _______    , _______    , _______, _______, _______, _______, _______, _______, _______, \
  _______, MO(_KANA_Z), _______    , MO(_KANA_D), MO(_KANA_B), _______, _______, _______, _______, _______, _______, _______, \
  _______, _______    , _______    , MO(_KANA_M), MO(_KANA_G), _______, _______, _______, _______, _______, _______, _______, \
  _______, _______    , _______    , _______    , _______    , _______, _______, _______, _______, _______, _______, _______ \
),
*/

[_KANA_K] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______    , _______, _______, _______, KANA_KI, KANA_KU, _______, _______, \
  _______, _______, _______, _______, _______    , _______, _______, KANA_KA, KANA_KE, KANA_KO, _______, _______, \
  _______, _______, _______, _______, _______    , _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, MO(_KANA_G), _______, _______, _______, _______, _______, _______, _______ \
),
[_KANA_G] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, KANA_GI, KANA_GU, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KANA_GA, KANA_GE, KANA_GO, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_KANA_S] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______    , _______, _______, _______, KANA_SI, KANA_SU, _______, _______, \
  _______, _______, _______, _______, _______    , _______, _______, KANA_SA, KANA_SE, KANA_SO, _______, _______, \
  _______, _______, _______, _______, _______    , _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, MO(_KANA_Z), _______, _______, _______, _______, _______, _______, _______ \
),
[_KANA_Z] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, KANA_ZI, KANA_ZU, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KANA_ZA, KANA_ZE, KANA_ZO, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_KANA_T] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______    , _______, _______, _______, KANA_TI, KANA_TU, _______, _______, \
  _______, _______, _______, _______, _______    , _______, _______, KANA_TA, KANA_TE, KANA_TO, KANA_XU, _______, \
  _______, _______, _______, _______, _______    , _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, MO(_KANA_D), _______, _______, _______, _______, _______, _______, _______ \
),
[_KANA_D] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, KANA_DI, KANA_DU, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KANA_DA, KANA_DE, KANA_DO, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_KANA_N] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, KANA_NI, KANA_NU, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KANA_NA, KANA_NE, KANA_NO, KANA_NN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_KANA_H] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______    , _______, _______, _______, KANA_HI, KANA_HU, _______, _______, \
  _______, _______, _______, _______, _______    , _______, _______, KANA_HA, KANA_HE, KANA_HO, _______, _______, \
  _______, _______, _______, _______, _______    , _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, MO(_KANA_B), _______, _______, _______, _______, _______, _______, _______ \
),
[_KANA_B] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, KANA_BI, KANA_BU, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KANA_BA, KANA_BE, KANA_BO, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
[_KANA_P] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, KANA_PI, KANA_PU, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KANA_PA, KANA_PE, KANA_PO, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_KANA_M] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, KANA_MI, KANA_MU, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KANA_MA, KANA_ME, KANA_MO, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_KANA_R] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, KANA_RI, KANA_RU, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KANA_RA, KANA_RE, KANA_RO, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_KANA_Y] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______    , _______, _______, _______, _______, KANA_YU, _______, _______, \
  _______, _______, _______, _______, _______    , _______, _______, KANA_YA, _______, KANA_YO, _______, _______, \
  _______, _______, _______, _______, _______    , _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, MO(_KANA_L), _______, _______, _______, _______, _______, _______, _______ \
),
[_KANA_L] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KANA_LU, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KANA_LA, _______, KANA_LO, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_KANA_W] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_TILD, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KANA_WA, KC_MINS, KANA_WO, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
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
 * | Ctrl | Win  | Alt  | Esc  |Space |Mouse |Number|Space | Del  | VolD | VolU |Symbol|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTL, KC_LGUI, KC_LALT, KC_ESC,  KC_SPC,  TT(_MOUSE),  TT(_NUM),  KC_SPC,   KC_DEL, KC_VOLD, KC_VOLU, TT(_SYM) \
)
};

/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _CGx 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  CGx = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CGx] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_W,    KC_L,    KC_R,    KC_B,  KC_GRV,                      KC_UNDS,    KC_Y,    KC_I,    KC_U,   KC_V,  KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_DEL,    KC_S,    KC_N,    KC_T,    KC_D, KC_COMM,                       KC_DOT,    KC_A,    KC_E,    KC_O,   KC_H,  KC_SCLN,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_J,    KC_P,    KC_C,    KC_K,    KC_Q,                         KC_Z,    KC_M,    KC_F,    KC_G,   KC_X,   KC_ENT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                         LCTL_T(KC_ESC),   LSFT_T(KC_BSPC),   LOWER,     RAISE,  KC_SPC,  KC_LGUI \
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_PGUP, KC_HOME,   KC_UP,  KC_END, _______,                      _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX,                      _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), XXXXXXX,                      XXXXXXX, KC_WH_L, KC_BTN3, KC_WH_R, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_LCBR, KC_LABK, KC_RABK, KC_RCBR, _______,                      _______,    KC_7,    KC_8,    KC_9, KC_MINS, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, XXXXXXX,                      _______,    KC_4,    KC_5,    KC_6,    KC_0, KC_PERC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, KC_BSLS, KC_TILD, KC_PLUS,  KC_EQL, XXXXXXX,                      _______,    KC_1,    KC_2,    KC_3, KC_SLSH, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,  RGBRST, VLK_TOG, EEP_RST, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F11, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_VOLD,                      KC_VOLU,   KC_F4,   KC_F5,   KC_F6,  KC_F10, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  } else {
    return rotation;
  }
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Keys:"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _CGx:
            oled_write_P(PSTR(" CGx "), false);
            break;
    }
}

void render_layer_state(void) {
    oled_write_P(PSTR("     LAYER"), false);
    oled_write_P(PSTR(" L"), layer_state_is(_LOWER));
    oled_write_P(PSTR("|"), false);
    oled_write_P(PSTR("R "), layer_state_is(_RAISE));
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_default_layer_state();
    render_layer_state();
}

// Imported from ./oled/falling_stars.c
// void render_stars(void);

// Imported from ./oled/misha.c
void render_misha(void);

// Imported from ./oled/wpm.c
void render_wpm(void);

void oled_task_user(void) {
    if (is_master) {
      //render_stars();
      render_misha();
      oled_set_cursor(0, 5);
      oled_write("Misha\n", false);
      render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
      render_wpm();
    }
}

#endif//OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    //active = true;
    // set_timelog();
  }

  switch (keycode) {
    case CGx:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_CGx);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

#ifdef RGB_MATRIX_ENABLE

void suspend_power_down_keymap(void) { rgb_matrix_set_suspend_state(true); }

void suspend_wakeup_init_keymap(void) { rgb_matrix_set_suspend_state(false); }

void check_default_layer(uint8_t mode, uint8_t type) {
    switch (get_highest_layer(default_layer_state)) {
        case _CGx:
            rgb_matrix_layer_helper(HSV_CYAN, mode, rgb_matrix_config.speed, type);
            break;
    }
}

void rgb_matrix_indicators_user(void) {
    if (userspace_config.rgb_layer_change &&
#    ifdef RGB_DISABLE_WHEN_USB_SUSPENDED
        !g_suspend_state &&
#    endif
#    if defined(RGBLIGHT_ENABLE)
        (!rgblight_config.enable && rgb_matrix_config.enable)
#    else
        rgb_matrix_config.enable
#    endif
    ) {
        switch (get_highest_layer(layer_state)) {
            case _RAISE:
                rgb_matrix_layer_helper(HSV_CYAN, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
                break;
            case _LOWER:
                rgb_matrix_layer_helper(HSV_ORANGE, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
                break;
            case _ADJUST:
                rgb_matrix_layer_helper(HSV_MAGENTA, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
                break;
            default: {
                check_default_layer(IS_LAYER_ON(_MODS), LED_FLAG_UNDERGLOW);
                break;
            }
        }
        check_default_layer(0, LED_FLAG_MODIFIER);
    }
}
#endif

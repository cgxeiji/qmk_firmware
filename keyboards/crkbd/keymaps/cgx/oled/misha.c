#include QMK_KEYBOARD_H

#define MISHA_SIZE 128
#define MISHA_FRAMES 2

static const char PROGMEM misha[MISHA_FRAMES][MISHA_SIZE] = {
  { // idle 32x32
    0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0x30, 0x98, 0xcc, 0xe4, 0x12, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x18, 0x6c, 0xf6, 0xfa, 0x3d, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x7f, 0x30, 0x06, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x00, 0x80, 0x10, 0x20, 0x00, 0x00, 0x01, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0x8f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x40, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x07, 0x0f, 0x1e, 0x3c, 0x38, 0x38, 0x70, 0x60, 0x60, 0x40, 0xc0, 0xc0, 0x80,
    0x00, 0x00, 0x04, 0x08, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x01, 0x03, 0x01, 0x00, 0x00
  },
  { // bark 32x32
    0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0x38, 0x9c, 0xce, 0xe7, 0x70, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x18, 0x6c, 0xf6, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x70, 0x36, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x80, 0x80, 0x90, 0x10, 0x80, 0x80, 0x41, 0x40, 0xc0, 0xc0, 0x40, 0xc0, 0x80, 0x00,
    0x00, 0x00, 0xff, 0x8f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x03, 0x03, 0x03, 0x80, 0x80, 0x40, 0x40, 0xc0, 0x40, 0x40, 0x41, 0x21, 0x13, 0x8f, 0x00,
    0x00, 0x00, 0x03, 0x07, 0x0f, 0x1e, 0x3c, 0x38, 0x38, 0x70, 0x60, 0x60, 0x40, 0xc0, 0xc0, 0x80,
    0x00, 0x00, 0x06, 0x0b, 0x08, 0x10, 0x10, 0x20, 0x20, 0x21, 0x22, 0x14, 0x08, 0x21, 0x44, 0x04
  }
};

uint16_t misha_timer = 0;

void render_misha(void) {
  uint8_t current_wpm = get_current_wpm();
  if (current_wpm > 40) {
    uint16_t t = timer_elapsed(misha_timer);
    if (t > 250 - current_wpm) {
      misha_timer = timer_read();
      if (current_wpm % 3 != 0) {
        oled_write_raw_P(misha[0], MISHA_SIZE);
      } else {
        oled_write_raw_P(misha[1], MISHA_SIZE);
      }
    }
  } else {
    oled_write_raw_P(misha[0], MISHA_SIZE);
  }
}
#include QMK_KEYBOARD_H
#include "./utils.c"

#define MAX_FRAMES 14

char frames[MAX_FRAMES][6];
uint16_t wpm_timer = 0;
char buf[6];

void update_frame(uint8_t val) {
  char data[6] = "     \0";

  if (val > 20) {
    if (val < 30) {
      data[2] = ':';
    } else if (val < 40) {
      data[2] = '.';
    } else if (val < 50) {
      data[1] = ':';
      data[2] = '.';
      data[3] = ':';
    } else if (val < 60) {
      data[1] = '.';
      data[2] = 'o';
      data[3] = '.';
    } else if (val < 70) {
      strcpy(data, ":.o.:\0");
    } else if (val < 80) {
      strcpy(data, ".oOo.\0");
    } else if (val < 90) {
      strcpy(data, "oO0Oo\0");
    } else if (val < 100) {
      strcpy(data, "o000o\0");
    } else if (val < 110) {
      strcpy(data, "O000O\0");
    } else {
      strcpy(data, "00000\0");
    }
  }
  shift_array(frames, 0, data, MAX_FRAMES);
}

void render_wpm(void) {
  oled_write_P(PSTR("WPM: "), false);
  uint8_t current_wpm = get_current_wpm();
  sprintf(buf, "%5d", current_wpm);
  oled_write(buf, false);
  if (timer_elapsed(wpm_timer) > 500) {
    update_frame(current_wpm);
    wpm_timer = timer_read();
  }

  for (uint8_t i = 0; i < MAX_FRAMES; i++) {
    oled_write(frames[i], false);
  }
}

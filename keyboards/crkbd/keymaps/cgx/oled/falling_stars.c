#include QMK_KEYBOARD_H
#include "./utils.c"

#define MAX_ANIM 11

uint16_t anim_timer = 0;
char anim[MAX_ANIM][6];
bool active = false;

void update_anim(uint8_t val) {
  char data[6] = "     \0";
  if (active) {
    if (val != 0) {
      data[val - 1] = '*';
    }
    active = false;
  }

  shift_array(anim, 0, data, MAX_ANIM);
}

void render_stars(void) {
  unit8_t current_wpm = get_current_wpm();
  if (current_wpm != 0) {
    uint16_t t = timer_elapsed(anim_timer);
    if (t > 150 - current_wpm) {
      update_anim(t % 6);
      anim_timer = timer_read();
    }

    for (uint8_t i = 0; i < MAX_ANIM; i++) {
      oled_write(anim[i], false);
    }
  }
}

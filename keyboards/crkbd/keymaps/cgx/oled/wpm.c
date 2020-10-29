#include QMK_KEYBOARD_H
#include "./utils.c"

#define Y_INIT (2*OLED_FONT_HEIGHT+4)

// For horizontal displays, use OLED_DISPLAY_HEIGHT
#define WPM_FRAMES (OLED_DISPLAY_WIDTH-Y_INIT-3)

#define WPM_IMG_SIZE 32
#define WPM_IMG_FRAMES 17

uint8_t frames[WPM_FRAMES+1];
uint16_t wpm_timer = 0;
char buf[6];

#define WPM_MIN 40
#define WPM_MAX 100

void update_frame(uint8_t val) {
  uint8_t frame = 0;
  if (val > WPM_MIN) {
    if (val > WPM_MAX) {
      frame = WPM_IMG_FRAMES-1;
    } else {
      frame = (val-WPM_MIN)*(WPM_IMG_FRAMES - 1)/(WPM_MAX - WPM_MIN);
    }
  }
  shift_uint8_array(frames, 0, frame, WPM_FRAMES+1);
}

bool frame[WPM_IMG_SIZE];

bool * frame_builder(uint8_t val) {
  uint8_t from = WPM_IMG_SIZE / 2 - val;

  for (uint8_t i = 0; i < WPM_IMG_SIZE/2; i++) {
    frame[i] = (i >= from);
    frame[WPM_IMG_SIZE-1-i] = frame[i];
  }

  return frame;
}


void render_wpm(void) {
  oled_write_P(PSTR("WPM: "), false);
  uint8_t current_wpm = get_current_wpm();
  for (uint8_t x = 0; x < 32; x++) {
    oled_write_pixel(x, Y_INIT-3, true);
  }

  sprintf(buf, "%5d", current_wpm);
  oled_write(buf, false);

  if (timer_elapsed(wpm_timer) > 50) {
    update_frame(current_wpm);
    wpm_timer = timer_read();

    for (uint8_t y = 0; y < WPM_FRAMES; y++) {
      if (frames[y] != frames[y+1]) { // skip drawing the same shape
        frame_builder(frames[y]);
        for (uint8_t x = 0; x < 32; x++) {
          oled_write_pixel(x, y+Y_INIT, frame[x]);
        }
      }
    }

  }

  for (uint8_t x = 0; x < 32; x++) {
    oled_write_pixel(x, WPM_FRAMES+Y_INIT+2, true);
  }
}

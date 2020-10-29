#ifndef CGX_UTILS
#define CGX_UTILS

void shift_array(char a[][6], uint8_t idx, char data[], uint8_t max) {
  if (idx >= max) {
    return;
  }
  shift_array(a, idx+1, a[idx], max);
  strcpy(a[idx], data);
}

#endif //CGX_UTILS

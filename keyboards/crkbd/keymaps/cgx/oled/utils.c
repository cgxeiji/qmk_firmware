#ifndef CGX_UTILS
#define CGX_UTILS

void shift_array(char a[][6], uint8_t idx, char data[], uint8_t max) {
  if (idx >= max) {
    return;
  }
  shift_array(a, idx+1, a[idx], max);
  strcpy(a[idx], data);
}

void shift_uint8_array(uint8_t a[], uint8_t idx, uint8_t data, uint8_t max) {
  if (idx >= max) {
    return;
  }
  shift_uint8_array(a, idx+1, a[idx], max);
  a[idx] = data;
}

#endif //CGX_UTILS

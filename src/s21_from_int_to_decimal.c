#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;
  if (dst) {
    *dst = set_zero_decimal();
    dst->bits[0] = abs(src);

    if (src < 0) {
      s21_set_sign(dst, 1);
    }
  } else {
    error = 1;
  }
  return error;
}
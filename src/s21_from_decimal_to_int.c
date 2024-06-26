#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  *dst = 0;
  s21_truncate(src, &src);
  if (src.bits[2] == 0 && src.bits[1] == 0 &&
      ((src.bits[0] <= 2147483647 && s21_get_sign(src) == 0) ||
       (src.bits[0] <= 2147483648 && s21_get_sign(src) == 1))) {
    *dst = (int)src.bits[0];
    *dst = s21_get_sign(src) == 1 ? -(*dst) : *dst;
  } else {
    error = 1;
  }
  return error;
}

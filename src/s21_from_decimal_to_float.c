#include <math.h>

#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0;
  if (s21_valid_decimal(&src) && dst != NULL) {
    *dst = 0.0f;
    double transform_dec = 0.0;
    for (int i = 0; i < 96; i++) {
      transform_dec += s21_get_bit(src, i) * pow(2, i);  // получили мантиссу
    }
    transform_dec =
        transform_dec * pow(10, -s21_get_scale(src));  // 10^(от 0 до 28)
    if (s21_get_sign(src)) {
      transform_dec = -transform_dec;  // если sign истина(т.е. 1)
    }
    *dst = (float)transform_dec;
  } else {
    error = 1;
  }

  return error;
}
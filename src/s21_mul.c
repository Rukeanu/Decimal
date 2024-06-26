#include "s21_decimal.h"

int s21_mul(s21_decimal dec1, s21_decimal dec2, s21_decimal *result) {
  s21_big_decimal a = convert_to_big(dec1);
  s21_big_decimal b = convert_to_big(dec2);
  s21_big_decimal buf = set_zero_big_dec();
  uint64_t big_digit = 0;
  uint32_t overflow;
  for (int i = 0; i < 3; i++) {
    s21_big_decimal tmp = set_zero_big_dec();
    overflow = 0;
    for (int j = 0; j < 3; j++) {
      big_digit = a.bits[i];
      big_digit *= b.bits[j];
      big_digit += overflow;
      overflow = big_digit >> 32;
      tmp.bits[i + j] = big_digit;
    }
    tmp.bits[i + 3] = overflow;
    sum_normalized(buf, tmp, &buf);
  }
  buf.sign = a.sign ^ b.sign;
  buf.scale = a.scale + b.scale;
  return fit_big_dec(buf, result);
}
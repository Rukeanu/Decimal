#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big_decimal value_b1 = convert_to_big(value_1);
  s21_big_decimal value_b2 = convert_to_big(value_2);
  set_common_scale(&value_b1, &value_b2);
  if (value_b1.sign == value_b2.sign) {
    add(&value_b1, value_b2);
  } else if (compare(value_b1, value_b2) == 1) {
    sub(&value_b1, value_b2);
  } else if (compare(value_b1, value_b2) == 2) {
    sub(&value_b2, value_b1);
    value_b1 = value_b2;
  } else if (compare(value_b1, value_b2) == 0) {
    value_b1 = set_zero_big_dec();
  }
  return fit_big_dec(value_b1, result);
}
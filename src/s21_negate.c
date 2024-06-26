#include "s21_decimal.h"

int s21_negate(s21_decimal decimal, s21_decimal *result) {
  if (!result) {
    return 1;
  }
  int error = 0;
  *result = set_zero_decimal();

  *result = decimal;
  s21_get_sign(decimal) ? s21_set_sign(result, 0) : s21_set_sign(result, 1);
  if (!s21_valid_decimal(&decimal)) error = 1;

  return error;
}
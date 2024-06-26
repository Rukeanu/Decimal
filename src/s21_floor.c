#include "s21_decimal.h"

int s21_floor(s21_decimal decimal, s21_decimal *result) {
  if (!result || !s21_valid_decimal(&decimal)) {
    return 1;
  }
  s21_decimal zero;
  zero = set_zero_decimal();
  *result = set_zero_decimal();

  int sign = s21_get_sign(decimal);

  s21_decimal fract;
  s21_decimal val_unsign_trunc;  // бззнаковая переменная исходного числа
                                 // транкейт
  s21_decimal val_unsign = decimal;

  if (sign == 1) {
    s21_negate(decimal, &val_unsign);
  }

  s21_truncate(val_unsign, &val_unsign_trunc);
  s21_sub(val_unsign, val_unsign_trunc, &fract);

  if (sign == 1 && s21_is_not_equal(fract, zero) == 1) {
    s21_add(val_unsign_trunc, dec_pow_ten(0), &val_unsign_trunc);
  }
  *result = val_unsign_trunc;
  s21_set_sign(result, sign);

  return 0;
}
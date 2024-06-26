#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result && s21_valid_decimal(&value)) {
    uint64_t rem = 0;  // остаток

    int scale = s21_get_scale(value);

    while (scale > 0) {
      for (int i = 2; i > -1; i--) {
        uint64_t num = value.bits[i];  // число
        num += rem << 32;              // прибавка остатка
        rem = num % 10;
        num /= 10;
        value.bits[i] = num;
      }
      scale--;
      rem = 0;
    }
    s21_set_scale(&value, 0);
    *result = value;
  } else {
    error = 1;
  }
  return error;
}
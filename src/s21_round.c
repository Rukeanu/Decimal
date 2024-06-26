#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_decimal half = {{5}};  // 0.5
  // установить порядковую степень half равной 1
  s21_set_pow(&half, 1);
  // обнулить переменную result
  *result = set_zero_decimal();
  // получить порядковую степень value
  int pow = s21_get_pow(value);
  // записать значение value в переменную result
  *result = value;

  // если порядковая степень value != 0, то выполнять следующие действия
  if (pow) {
    // если знак value отрицательный, то результат будет - 0.5
    if (s21_get_sign(value)) {
      s21_sub(value, half, result);  // result = value - 0.5
      // если знак value положительный, то результат будет + 0.5
    } else {
      s21_add(value, half, result);  // result = value + 0.5
    }
  }
  // обрезать дробную часть результата и записать в result
  s21_truncate(*result, result);
  // вернуть 0
  return 0;
}
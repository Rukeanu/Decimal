#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = check_float(src, dst);  // проверка значения
  if (dst) {  // пустой ли указатель на decimal?
    *dst = set_zero_decimal();
    long int newsrc =
        (long int)src;  // перенос значения в long int, отброс дробной части
    long int exp = 0;  // 32-битная переменная для экспоненты
    while (src - ((float)newsrc / (long int)(pow(10, exp))) !=
           0) {  // цикл, пока основное значение не будет равно
                 // децималу(d=V/10^exp)
      exp++;  // пока цикл идёт, увеличиваем экспоненту
      newsrc =
          src * (long int)pow(
                    10, exp);  // выражаем из формулы "децимала" основное
                               // значение и присваиваем его новой переменной
    }
    s21_from_int_to_decimal(newsrc, dst);  // заполняем мантиссу
    if (src < 0) s21_set_sign(dst, 1);
    dst->bits[3] += exp << 16;  // заполняем значение экпоненты побитово
  } else
    error = 1;  // если указатель на decimal пуст, ошибка = 1
  return error;
}

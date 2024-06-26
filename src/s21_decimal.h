#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOP_SEVEN_DIGITS 7922816

// #define MINUS 0x80000000  // 100000000 000000000 000000000 000000000

#define SC 0x00ff0000  // 000000000 11111111 000000000 000000000 (scale)

#define MAX4BITE 0xffffffff
// bits[i] = bits[j]&MAX4BITE;

typedef unsigned int s21_bits;

typedef struct s21_decimal {
  unsigned int bits[4];
} s21_decimal;

typedef struct s21_big_decimal {
  s21_bits bits[8];
  int sign;
  int scale;
} s21_big_decimal;

#include "supportf.h"

#define S21_MAX_DECIMAL 2e96 - 1
#define S21_MIN_DECIMAL -2e96 - 1

// x00000000 000zzzzz 000000000 000000000 (bits[3]) bits[2] bits[1] bits[0]
// (мантисса) x - биты для знака zzzzz - биты для scale, т.е. pow(10,(-scale))

//___________________________________________Арифметические_операторы_(функции_с_нормализованными_числами)_________________________________________

int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // сложение - addition
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // вычитание - subtraction
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // умножение - multiplication
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  // деление - division

// Функции возвращают код ошибки:
// - 0 - OK
// - 1 - число слишком велико или равно бесконечности
// - 2 - число слишком мало или равно отрицательной бесконечности
// - 3 - деление на 0

//_________________________________________________________Операторы_сравнения_____________________________________________________________________

int s21_is_less(s21_decimal, s21_decimal);              // <
int s21_is_less_or_equal(s21_decimal, s21_decimal);     // <=
int s21_is_greater(s21_decimal, s21_decimal);           // >
int s21_is_greater_or_equal(s21_decimal, s21_decimal);  // >=
int s21_is_equal(s21_decimal, s21_decimal);             // ==
int s21_is_not_equal(s21_decimal, s21_decimal);         // !=

// Возвращаемое значение:
// - 0 - FALSE
// - 1 - TRUE

//______________________________________________Преобразователи_(конвертация)______________________________________________________________________

int s21_from_int_to_decimal(int src, s21_decimal *dst);      // Из int
int s21_from_decimal_to_int(s21_decimal src, int *dst);      // В int
int s21_from_float_to_decimal(float src, s21_decimal *dst);  // Из float
int s21_from_decimal_to_float(s21_decimal src, float *dst);  // В float

// Возвращаемое значение - код ошибки:
//  - 0 - OK
//  - 1 - ошибка конвертации

//__________________________________Преобразователи(округление_и_трансформация_в_отрицательное/положительное)____________________________________________________

int s21_floor(s21_decimal value,
              s21_decimal *result);  // Округляет указанное Decimal число до
                                     // ближайшего целого числа в сторону
                                     // отрицательной бесконечности.
int s21_round(
    s21_decimal value,
    s21_decimal *result);  //  Округляет Decimal до ближайшего целого числа.
int s21_truncate(s21_decimal value,
                 s21_decimal *result);  // Возвращает целые цифры указанного
                                        // Decimal числа; любые дробные цифры
                                        // отбрасываются, включая конечные нули.
int s21_negate(s21_decimal value,
               s21_decimal *result);  // Возвращает результат умножения
                                      // указанного Decimal на -1.

// int s21_bank(s21_decimal value, s21_decimal *result);  // банковское
// округление Возвращаемое значение - код ошибки:
//  - 0 - OK
//  - 1 - ошибка вычисления

//_____________________________________________Трансформация_децимал_в_БИГ_и_обратно_______________________________________________________________
// void s21_from_dec_to_big(
//     s21_decimal number_1,
//     s21_big_decimal *number_2);  // конвертация децимал в биг децимал
// void s21_from_big_to_dec(
//     s21_decimal *number_1,
//     s21_big_decimal number_2);  // конвертация из биг децимал в децимал

//______________________________________________Дополнительные_функции_____________________________________________________________________________

// int s21_get_big_bit(s21_big_decimal dst, int index);

// void s21_set_bit(s21_decimal *dst, int index,
//                  int bit);  // изменение значения конкретного бита
// void s21_set_big_bit(s21_big_decimal *dst, int index, int bit);

// void s21_set_sign(s21_decimal *dst);  // изменение значения знака

// void s21_set_sign_zero(s21_decimal *dst);  // зануление знака

// void s21_clear_dec(s21_decimal *number);          // зануление decimal
// void s21_clear_big_dec(s21_big_decimal *number);  // зануление big decimal

// int s21_strlen_big(
//     s21_big_decimal value);  // возвращает длину big dec(ищет побитово первое
//                              // вхождение 1 со старшего бита)

// void s21_copy_dec(const s21_decimal *src,
//                   s21_decimal *dest);  // копирование decimal

//__________________________________________________________Сдвиг/Shift____________________________________________________________________________
// ПЕРЕПИСАТЬ!!!!!
// void s21_shift_left(s21_decimal *num);  // сдвиг влево на 1
// void s21_left_shift(s21_decimal *number, int shift_value);  // сдвиг влево
// void s21_right_shift(s21_decimal *number, int shift_value);  // сдвиг вправо

//_______________________________________________Бинарные_арифметические_операции__________________________________________________________________

// void s21_binary_add(s21_big_decimal value_1, s21_big_decimal value_2,
//                     s21_big_decimal *result);  // сложение бинарное -
//                     addition
// void s21_binary_sub(
//     s21_big_decimal value_1, s21_big_decimal value_2,
//     s21_big_decimal *result);  // вычитание бинарное - subtraction
// void s21_binary_mul(
//     s21_big_decimal value_1, s21_big_decimal value_2,
//     s21_big_decimal *result);  // умножение бинарное - multiplication
// void s21_binary_div(/*s21_decimal permanent_value_1,*/ s21_big_decimal
// value_1,
//                     s21_big_decimal value_2,
//                     s21_big_decimal *result);  // деление бинарное - division
// // Простые арифметические операции предполагающие, что числа положительные и
// // имеют нулевую степень, Эти функции будут вызываться в
// // других(нормализованных) арифметических операциях

// //___________________________________________________________Нормализация__________________________________________________________________________

// void s21_normalize_scale(s21_decimal *src,
//                          int scale);  // нормализация scale
// void s21_normalize(s21_decimal *value1,
//                    s21_decimal *value2);  // нормализация decimal

//_________________________________________________________Логические_операции_____________________________________________________________________

// void s21_binary_and(s21_decimal value_1, s21_decimal value_2,
//                     s21_decimal *result);  // бинарное "И"
// void s21_binary_xor(s21_decimal value_1, s21_decimal value_2,
//                     s21_decimal *result);  // бинарное исключающее "ИЛИ"

// void s21_binary_not(s21_decimal *result);  // бинарное дополнение
// void s21_binary_not_big(s21_big_decimal *result);

//________________________________________________________________Печать___________________________________________________________________________

// void s21_print_bits(int num);  // печатает int побитово
// void s21_print_decimal(s21_decimal num);  // выводит децимал побитово
// void s21_print_big_decimal(s21_big_decimal num);  // выводит биг децимал
//                                                   // побитово
// void s21_print_big_dec_normal(
//     s21_big_decimal num);  // выводит биг децимал как десятичное число

#endif
#include "supportf.h"

//_____________________________________________________PRINT_decimal_________________________________________________________

// void s21_print_big_dec_normal(s21_big_decimal num) {
//   for (int i = 7; i >= 0; i--) {
//     printf("%d", num.bits[i]);
//   }
// }

// void s21_print_bits(int num) {
//   for (int i = 31; i >= 0; i--) {
//     if (i % 8 == 0 && i != 0) {
//       printf("%d ", (num >> i) & 1);
//     } else
//       printf("%d", (num >> i) & 1);
//   }
//   printf("\n");
// }

// void s21_print_decimal(s21_decimal num) {
//   for (int i = 3; i >= 0; i--) {
//     s21_print_bits(num.bits[i]);
//   }
//   printf("\n");
// }

// void s21_print_big_decimal(s21_big_decimal num) {
//   for (int i = 7; i >= 0; i--) {
//     s21_print_bits(num.bits[i]);
//   }
//   printf("\n");
// }

//_____________________________________________________GET/SET_bit____________________________________________________________

// возвращает 0 или 1
int s21_get_bit(s21_decimal dst, int index) {
  int mask = 1u << (index % 32);  // вычисление индекса бита и сдвиг
  return (dst.bits[index / 32] & mask) >> index;  // вычисление номера инта
}

int s21_get_bit_for_round(int src, int pos) {
  if (src & (1 << pos)) {
    return 1;
  } else {
    return 0;
  }
}

// void s21_set_bit(s21_decimal *dst, int index, int bit) {
//   unsigned int mask = 1u << (index % 32);  // узнаем индекс бита в блоке
//   (инте) if (bit == 0)
//     dst->bits[index / 32] =
//         dst->bits[index / 32] & ~mask;  // сбросить бит в 0 в структуре
//   else
//     dst->bits[index / 32] =
//         dst->bits[index / 32] | mask;  // установить бит в 1 в структуре
// }

// int s21_get_big_bit(s21_big_decimal dst, int index) {
//   int mask = 1u << (index % 32);
//   return (dst.bits[index / 32] & mask) >> index;
// }

// void s21_set_big_bit(s21_big_decimal *dst, int index, int bit) {
//   int mask = 1u << (index % 32);
//   if (bit == 0)
//     dst->bits[index / 32] = dst->bits[index / 32] & ~mask;
//   else
//     dst->bits[index / 32] = dst->bits[index / 32] | mask;
// }

//_____________________________________________________GET/SET_sign____________________________________________________________

int s21_get_sign(s21_decimal dst) { return (dst.bits[3] & 1u << 31) >> 31; }

// void s21_set_sign(s21_decimal *dst) { dst->bits[3] = dst->bits[3] | 1u << 31;
// }

void s21_set_sign(s21_decimal *dec, bool sign) {
  setIntBit((int *)&(dec->bits[3]), 31, sign);
}

// void s21_set_sign_zero(s21_decimal *dst) {
//   dst->bits[3] = dst->bits[3] & 0u << 31;
// }

void setIntBit(int *var, int id, int val) {
  if (id < 0 || id > 31) type_error("'id' must be in 0-31 range");
  if (val < 0 || val > 1) type_error("'val' must be in 1 or 0");
  *var &= ~(1 << id);
  *var |= (val << id);
}

void type_error(char *message) {
  fprintf(stderr, "TypeError: %s\n", message);
  exit(1);
}

//_____________________________________________________GET/SET_scale____________________________________________________________

int s21_get_scale(s21_decimal dst) {
  int mask = 127 << 16;  // извлекаем scale
  int scale = (mask & dst.bits[3]) >> 16;  // получаем биты для scale и сдвигаем
  return scale;
}

void s21_set_scale(s21_decimal *dst, int scale) {
  int sign;
  sign = s21_get_sign(*dst);
  dst->bits[3] = 0;
  dst->bits[3] = (scale <<= 16) | dst->bits[3];
  if (sign) s21_set_sign(dst, 1);
}

//_____________________________________________________SHIFT_LEFT/RIGHT____________________________________________________________

// void s21_shift_left(s21_decimal *num) {
//   unsigned memory = 0;
//   for (int i = 0; i < 4; ++i) {
//     unsigned temp = num->bits[i];
//     num->bits[i] <<= 1;
//     num->bits[i] |= memory;
//     memory = temp >> (32 - 1);
//   }
// }

// void s21_shift_big_left(s21_big_decimal *num, int value) {
//   unsigned memory = 0;
//   for (int i = 0; i < 8; ++i) {
//     unsigned temp = num->bits[i];
//     num->bits[i] <<= value;
//     num->bits[i] |= memory;
//     memory = temp >> (32 - value);
//   }
// }

// void s21_shift_right(s21_big_decimal *num) {
//   int res = 0;
//   for (int i = 0; i < 256; i++) {
//     res = s21_get_big_bit(*num, i + 1);
//     s21_set_big_bit(num, i, res);
//   }
// }

//_____________________________________________________CLEAR/COPY/STRLEN_decimal____________________________________________________________

// void s21_clear_dec(s21_decimal *number) {
//   for (int i = 0; i < 4; i++) number->bits[i] = 0;
// }

// void s21_clear_big_dec(s21_big_decimal *number) {
//   for (int i = 0; i < 8; i++) number->bits[i] = 0;
// }

// void s21_copy_dec(const s21_decimal *src, s21_decimal *dest) {
//   for (int i = 0; i <= 3; i++) {
//     dest->bits[i] = src->bits[i];
//   }
// }

// void s21_copy_dec_big(const s21_big_decimal *src, s21_big_decimal *dest) {
//   for (int i = 0; i <= 7; i++) {
//     dest->bits[i] = src->bits[i];
//   }
// }

// int s21_strlen(s21_decimal value) {
//   for (int len = 127; len >= 0; len--) {
//     if (s21_get_bit(value, len) == 1) return len;
//   }
//   return 0;
// }

// int s21_strlen_big(s21_big_decimal value) {
//   for (int len = 255; len >= 0; len--) {
//     if (s21_get_big_bit(value, len) == 1) return len;
//   }
//   return 0;
// }

//_____________________________________________________CONVERTER_big/small_decimal______________________________________________________

// void s21_from_dec_to_big(s21_decimal number_1, s21_big_decimal *number_2) {
//   for (int i = 0; i < 4; i++) {
//     number_2->bits[i] = number_1.bits[i];
//   }
// }

// void s21_from_big_to_dec(s21_decimal *number_1, s21_big_decimal number_2) {
//   for (int i = 0; i < 4; i++) {
//     number_1->bits[i] = number_2.bits[i];
//   }
// }

//_____________________________________________________NO/Logic/Operations____________________________________________________________

// void s21_binary_not(s21_decimal *result) {
//   for (int i = 0; i <= 3; i++) {
//     result->bits[i] = ~(result->bits[i]);
//   }
// }

// void s21_binary_not_big(s21_big_decimal *result) {
//   for (int i = 0; i <= 7; i++) {
//     result->bits[i] = ~(result->bits[i]);
//   }
// }

// void s21_binary_and(s21_decimal value_1, s21_decimal value_2,
//                     s21_decimal *result) {
//   for (int i = 0; i <= 3; i++) {
//     result->bits[i] = value_1.bits[i] & value_2.bits[i];
//   }
// }

// void s21_binary_and_big(s21_big_decimal value_1, s21_big_decimal value_2,
//                         s21_big_decimal *result) {
//   for (int i = 0; i <= 7; i++) {
//     result->bits[i] = value_1.bits[i] & value_2.bits[i];
//   }
// }

// void s21_binary_or(s21_decimal value_1, s21_decimal value_2,
//                    s21_decimal *result) {
//   for (int i = 0; i <= 3; i++) {
//     result->bits[i] = value_1.bits[i] | value_2.bits[i];
//   }
// }

// void s21_binary_or_big(s21_big_decimal value_1, s21_big_decimal value_2,
//                        s21_big_decimal *result) {
//   for (int i = 0; i <= 7; i++) {
//     result->bits[i] = value_1.bits[i] | value_2.bits[i];
//   }
// }

// void s21_binary_xor(s21_decimal value_1, s21_decimal value_2,
//                     s21_decimal *result) {
//   for (int i = 0; i <= 3; i++) {
//     result->bits[i] = value_1.bits[i] ^ value_2.bits[i];
//   }
// }

// void s21_binary_xor_big(s21_big_decimal value_1, s21_big_decimal value_2,
//                         s21_big_decimal *result) {
//   for (int i = 0; i <= 7; i++) {
//     result->bits[i] = value_1.bits[i] ^ value_2.bits[i];
//   }
// }

//_____________________________________________________Arithmetic____________________________________________________________

// void s21_binary_add(s21_big_decimal value_1, s21_big_decimal value_2,
//                     s21_big_decimal *result) {
//   int res = 0, ovf = 0;
//   for (int i = 0; i < 256; i++) {
//     res = s21_get_big_bit(value_1, i) + s21_get_big_bit(value_2, i) + ovf;
//     ovf = res / 2;
//     s21_set_big_bit(result, i, res % 2);
//   }
// }

// void s21_binary_sub(s21_big_decimal value_1, s21_big_decimal value_2,
//                     s21_big_decimal *result) {
//   int res = 0, tmp = 0, comp = 0;
//   comp = compare(value_1, value_2);
//   if (comp == 0 || comp == 1) {
//     for (int i = 0; i < 256; i++) {
//       res = s21_get_big_bit(value_1, i) - s21_get_big_bit(value_2, i) - tmp;
//       tmp = res < 0 ? 1 : 0;
//       res = abs(res);
//       s21_set_big_bit(result, i, res % 2);
//     }
//   } else {
//     for (int i = 0; i < 256; i++) {
//       res = s21_get_big_bit(value_2, i) - s21_get_big_bit(value_1, i) - tmp;
//       tmp = res < 0 ? 1 : 0;
//       res = abs(res);
//       s21_set_big_bit(result, i, res % 2);
//     }
//   }
// }

// void s21_binary_mul(s21_big_decimal value_1, s21_big_decimal value_2,
//                     s21_big_decimal *result) {
//   for (int i = s21_strlen_big(value_2) - 1; i >= 0; i--) {
//     if (s21_get_big_bit(value_2, i) == 1) {
//       s21_binary_add(*result, value_1, result);
//       s21_shift_big_left(&value_1, 1);
//     } else
//       s21_shift_big_left(&value_1, 1);
//   }
// }

// void s21_mul_by_ten(s21_big_decimal *number, int count) {
//   for (int i = 0; i < count; i++) {
//     s21_big_decimal number_1 = *number;
//     s21_shift_big_left(number, 3);
//     s21_shift_big_left(&number_1, 1);
//     s21_binary_add(*number, number_1, number);
//   }
// }

// разница степеней (scale) обоих чисел
// int s21_diff_scale(s21_decimal value_1, s21_decimal value_2) {
//   // зануляем бит отвечающий за знак
//   s21_set_bit(&value_1, 127, 0);
//   s21_set_bit(&value_2, 127, 0);

//   // узнём разницу степеней
//   int diff_scale = value_1.bits[3] - value_2.bits[3];
//   if (diff_scale < 0) {
//     diff_scale = diff_scale * (-1);
//   }

//   return diff_scale;
// }

s21_decimal set_zero_decimal(void) {
  s21_decimal decimal;
  for (int i = 0; i < 4; i++) decimal.bits[i] = 0;
  return decimal;
}

s21_big_decimal set_zero_big_dec(void) {
  s21_big_decimal decimal;
  for (int i = 0; i < 8; i++) decimal.bits[i] = 0;
  decimal.sign = 0;
  decimal.scale = 0;
  return decimal;
}

int s21_get_pow(s21_decimal src) {
  int dst = 0;
  for (int i = 16; i <= 23; i++) {
    dst += s21_get_bit_for_round(src.bits[3], i) * ((int)pow(2, i - 16));
  }
  return dst;
}

// проверяет src на предмет оч маленьких чисел (близких к нулю)
int check_float(float src, s21_decimal *dst) {
  int error = 0;
  if (fabs(src) < 1e-28) {
    error = 1;
    *dst = set_zero_decimal();
  } else if (fabs(src) > S21_MAX_DECIMAL) {
    error = 1;
  }

  return error;
}

s21_big_decimal convert_to_big(s21_decimal dec) {
  s21_big_decimal res;
  res = set_zero_big_dec();
  for (int i = 0; i < 3; i++) res.bits[i] = dec.bits[i];
  res.sign = s21_get_sign(dec);
  res.scale = s21_get_scale(dec);
  return res;
}

s21_decimal convert_from_big(s21_big_decimal dec) {
  s21_decimal res = set_zero_decimal();
  for (int i = 0; i < 3; i++) res.bits[i] = dec.bits[i];
  s21_set_sign(&res, dec.sign);
  s21_set_scale(&res, dec.scale);
  return res;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_v1 = convert_to_big(value_1);
  s21_big_decimal big_v2 = convert_to_big(value_2);
  int comp, res;
  set_common_scale(&big_v1, &big_v2);
  comp = compare(big_v1, big_v2);
  if (big_v1.sign == big_v2.sign) {
    res = comp == 0 ? 1 : 0;
  } else {
    res = eq_zero_big(big_v1) && comp == 0 ? 1 : 0;
  }
  return res;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = s21_is_equal(value_1, value_2);
  if (res) {
    res = 0;
  } else if (!res) {
    res = 1;
  }

  return res;
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_v1 = convert_to_big(value_1);
  s21_big_decimal big_v2 = convert_to_big(value_2);
  int comp, res;
  set_common_scale(&big_v1, &big_v2);
  comp = compare(big_v1, big_v2);
  if (big_v1.sign == big_v2.sign)
    if (big_v1.sign == 1)
      res = comp == 1 ? 1 : 0;
    else
      res = comp == 2 ? 1 : 0;
  else
    res = big_v1.sign == 1 && comp != 0 ? 1 : 0;
  return res;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_v1 = convert_to_big(value_1);
  s21_big_decimal big_v2 = convert_to_big(value_2);
  int comp, res;
  set_common_scale(&big_v1, &big_v2);
  comp = compare(big_v1, big_v2);
  if (big_v1.sign == big_v2.sign)
    if (big_v1.sign == 1)
      res = comp == 2 ? 1 : 0;
    else
      res = comp == 1 ? 1 : 0;
  else
    res = big_v1.sign == 0 && comp != 0 ? 1 : 0;
  return res;
}

void add(s21_big_decimal *value_b1, s21_big_decimal value_b2) {
  unsigned long long int mant_tmp = 0, next = 0;
  for (int i = 0; i <= 7; i++) {
    mant_tmp = (unsigned long long)value_b1->bits[i] +
               (unsigned long long)value_b2.bits[i] + next;
    value_b1->bits[i] = mant_tmp & 4294967295;
    next = mant_tmp >> 32;
  }
}

void sub(s21_big_decimal *tmp, s21_big_decimal tmp_lower) {
  unsigned long long int mant_tmp = 0, next = 0;
  for (int i = 0; i <= 7; i++) {
    mant_tmp = 4294967296 + (unsigned long long)tmp->bits[i] -
               (unsigned long long)tmp_lower.bits[i] - next;
    if ((mant_tmp & 4294967296) != 0) {
      mant_tmp -= 4294967296;
      next = 0;
    } else {
      next = 1;
    }
    tmp->bits[i] = mant_tmp;
  }
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_v1 = convert_to_big(value_1);
  s21_big_decimal big_v2 = convert_to_big(value_2);
  int comp, res;
  set_common_scale(&big_v1, &big_v2);
  comp = compare(big_v1, big_v2);
  if (big_v1.sign == big_v2.sign)
    if (big_v1.sign == 1)
      res = comp != 1 ? 1 : 0;
    else
      res = comp != 2 ? 1 : 0;
  else
    res = big_v1.sign == 0 || (eq_zero_big(big_v1) && comp == 0) ? 1 : 0;
  return res;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_v1 = convert_to_big(value_1);
  s21_big_decimal big_v2 = convert_to_big(value_2);
  int comp, res;
  set_common_scale(&big_v1, &big_v2);
  comp = compare(big_v1, big_v2);
  if (big_v1.sign == big_v2.sign)
    if (big_v1.sign == 1)
      res = comp != 2 ? 1 : 0;
    else
      res = comp != 1 ? 1 : 0;
  else
    res = big_v1.sign == 1 || (eq_zero_big(big_v1) && comp == 0) ? 1 : 0;
  return res;
}

void set_common_scale(s21_big_decimal *big_v1, s21_big_decimal *big_v2) {
  unsigned char scale_div;
  if (big_v2->scale > big_v1->scale) {
    scale_div = abs(big_v2->scale - big_v1->scale);
    big_v1->scale = big_v2->scale;
    normalize(big_v1, scale_div);
  } else {
    scale_div = abs(big_v1->scale - big_v2->scale);
    big_v2->scale = big_v1->scale;
    normalize(big_v2, scale_div);
  }
}

void normalize(s21_big_decimal *tmp, unsigned char scale_div) {
  long long int mant_tmp = 0, next = 0;
  for (int j = scale_div; j != 0; j--) {
    for (int i = 0; i <= 7; i++) {
      mant_tmp = tmp->bits[i];
      mant_tmp = mant_tmp * 10;
      tmp->bits[i] = mant_tmp & 4294967295;
      tmp->bits[i] = tmp->bits[i] + next;
      next = mant_tmp >> 32;
    }
  }
}

// сравнение без учетом знака числа
int compare(s21_big_decimal big_v1, s21_big_decimal big_v2) {
  int result = 0;
  for (int i = 7; i >= 0 && result == 0; i--) {
    if (big_v1.bits[i] > big_v2.bits[i]) {
      result = 1;
    } else if (big_v1.bits[i] < big_v2.bits[i]) {
      result = 2;
    }
  }
  return result;
}

bool eq_zero_big(s21_big_decimal dec) {
  int res = 0;
  for (int i = 0; i < 7; i++) res += dec.bits[i] != 0;
  return !res;
}

int s21_valid_decimal(s21_decimal *value) {
  int valid = 1;
  if (!value || (value->bits[3] & 0xFFFF) != 0 ||
      (value->bits[3] >> 24 & 0x7F) != 0 || s21_get_scale(*value) > 28) {
    valid = 0;
  }
  return valid;
}

s21_decimal dec_pow_ten(int value) {
  POW_TEN;
  return pow_ten[value];
}

int s21_set_pow(s21_decimal *dst, int value) {
  int sign = s21_get_sign(*dst);
  // степень строго с 0 по 28
  if (value < 0 || value > 28) {
    return 1;
  }
  (dst->bits)[3] = 0;
  int id = 0;
  while (value > 0) {
    s21_set_bit_uns(&(dst->bits[3]), 16 + id, value % 2);
    value /= 2;
    id++;
  }
  s21_set_sign(dst, sign);
  return 0;
}

void s21_set_bit_uns(unsigned int *dst, int pos, int value) {
  if (value) {  // если хотим поставить 1
    *dst |= (1 << pos);
  } else {  // если хотим поставить 0
    *dst &= ~(1 << pos);
  }
}

// int s21_cmp_big_mant(s21_big_decimal value_1, s21_big_decimal value_2) {
//   // проверка равенства мантис, возвращает флаг большей мантисы, 1 - мантиса
//   1
//   // числа, 2 - второго, 0 - при равенстве
//   int flag = 0;
//   for (int i = 7; i >= 0 && !flag; i--) {
//     // сравниваем по интам структуры децимал
//     if (value_1.bits[i] > value_2.bits[i]) {
//       flag = 1;
//     } else if (value_1.bits[i] < value_2.bits[i]) {
//       flag = 2;
//     }
//   }
//   return flag;
// }

int s21_division_on_10(s21_big_decimal dec, s21_big_decimal *result) {
  uint64_t big_digit, rem = 0;
  if (result) *result = set_zero_big_dec();
  for (int i = 7; i >= 0; i--) {
    big_digit = dec.bits[i] + (rem << 32);
    rem = big_digit % 10;
    big_digit /= 10;
    if (result) result->bits[i] = big_digit;
  }
  if (result) {
    result->sign = dec.sign;
    result->scale = dec.scale;
  }
  return rem;
}

int fit_big_dec(s21_big_decimal dec, s21_decimal *res) {
  int error = 0, drop = 0, cumul = 0;
  int cnt = 0;
  while ((!is_fit(dec) && dec.scale) || dec.scale > 28) {
    cumul = cumul || drop;
    drop = s21_division_on_10(dec, &dec);
    dec.scale--;
    cnt++;  // итерации
  }
  if (!is_fit(dec))  // если переполнение
    error = 1;
  else if (cnt) {
    bank_rule(&dec, drop, cumul);
    if (!is_fit(dec))
      error = fit_big_dec(dec, res);
    else
      *res = convert_from_big(dec);
  } else
    *res = convert_from_big(dec);
  return !error ? 0 : (dec.sign ? 2 : 1);
}

int is_fit(s21_big_decimal dec) {
  int res = 1;  // dec может быть представлено в s21_decimal
  for (int i = 3; res && i < 8; i++)
    if (dec.bits[i]) res = 0;  // dec НЕ может быть представлено
  return res;
}

void bank_rule(s21_big_decimal *dec, int drop, int cumul) {
  int last = s21_division_on_10(*dec, NULL);
  int res = 0;
  if (drop > 5 || (drop == 5 && cumul > 0) || (drop == 5 && last % 2)) res = 1;
  s21_decimal round;
  s21_from_int_to_decimal(res, &round);
  sum_normalized(*dec, convert_to_big(round), dec);
}

int sum_normalized(s21_big_decimal val1, s21_big_decimal val2,
                   s21_big_decimal *result) {
  s21_big_decimal tmp = set_zero_big_dec();
  uint64_t big_digit;
  int mem = 0;
  for (int i = 0; i < 8; i++) {
    big_digit = val1.bits[i];
    big_digit += val2.bits[i];
    big_digit += mem;
    mem = big_digit >> 32;
    tmp.bits[i] = big_digit;
  }
  tmp.sign = val1.sign;
  tmp.scale = val1.scale;
  if (mem == 0) *result = tmp;
  return mem;
}

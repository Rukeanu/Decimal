#include "unit_tests.h"

START_TEST(int_to_decimal_1) {
  s21_decimal val = {{0, 0, 0, 0}};
  int result = 0;
  int number = 123456789;
  s21_from_int_to_decimal(number, &val);
  s21_from_decimal_to_int(val, &result);
  ck_assert_int_eq(result, number);
}
END_TEST

START_TEST(int_to_decimal_2) {
  s21_decimal val = {{0, 0, 0, 1}};
  int result = 0;
  int number = 123456789;
  s21_from_int_to_decimal(number, &val);
  s21_from_decimal_to_int(val, &result);
  ck_assert_int_eq(result, number);
}
END_TEST

START_TEST(int_to_decimal_3) {
  s21_decimal val = {{0, 0, 0, 0}};
  int result = 0;
  int number = -123456789;
  s21_from_int_to_decimal(number, &val);
  s21_from_decimal_to_int(val, &result);
  ck_assert_int_eq(result, number);
}
END_TEST

START_TEST(int_to_decimal_4) {
  s21_decimal val = {{0, 0, 0, 0}};
  int result = 0;
  int number = 16234;
  s21_from_int_to_decimal(number, &val);
  s21_from_decimal_to_int(val, &result);
  ck_assert_int_eq(result, number);
}
END_TEST

START_TEST(int_to_decimal_5) {
  int number = s21_from_int_to_decimal(123, NULL);
  ck_assert_int_eq(1, number);
}
END_TEST

Suite *suite_from_int_to_decimal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_int_to_decimal");
  tc = tcase_create("case_from_int_to_decimal");

  tcase_add_test(tc, int_to_decimal_1);
  tcase_add_test(tc, int_to_decimal_2);
  tcase_add_test(tc, int_to_decimal_3);
  tcase_add_test(tc, int_to_decimal_4);
  tcase_add_test(tc, int_to_decimal_5);

  suite_add_tcase(s, tc);
  return s;
}

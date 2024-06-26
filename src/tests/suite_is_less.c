#include "unit_tests.h"

START_TEST(is_less_1) {
  s21_decimal val1 = {{1, 0, 0, 393216}};  // 0.000001
  s21_decimal val2 = {{1, 0, 0, 196608}};  // 0.001

  ck_assert_int_eq(s21_is_less(val1, val2), 1);
}

START_TEST(is_less_2) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}

START_TEST(is_less_3) {
  s21_decimal val1 = {{0, 0, 1, (unsigned int)-65536}};
  s21_decimal val2 = {{0, 0, 1, 65536}};

  ck_assert_int_eq(s21_is_less(val1, val2), 1);
}

START_TEST(is_less_4) {
  s21_decimal val1 = {{4, 3, 2, 0}};  // 3.6893488160304E+19
  s21_decimal val2 = {{1, 3, 4, 0}};  // 7.3786976307723E+19

  ck_assert_int_eq(s21_is_less(val1, val2), 1);
}

START_TEST(is_less_5) {
  s21_decimal val1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_decimal val2 = {
      {12, 0, 0, 0b10000000000000010000000000000000}};  //  -1.2;

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}

START_TEST(is_less_6) {
  s21_decimal val1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_decimal val2 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}
START_TEST(is_less_7) {
  s21_decimal val1 = {
      {12345, 0, 0, 0b00000000000000110000000000000000}};  //  12.345
  s21_decimal val2 = {
      {1122345, 0, 0, 0b00000000000001010000000000000000}};  //  11.22345
  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}

START_TEST(is_less_8) {
  s21_decimal val1 = {{0, 0, 0, (unsigned int)-2147483648}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(val1, val2), 0);
}

Suite *suite_is_less(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_is_less");
  tc = tcase_create("case_is_less");

  tcase_add_test(tc, is_less_1);
  tcase_add_test(tc, is_less_2);
  tcase_add_test(tc, is_less_3);
  tcase_add_test(tc, is_less_4);
  tcase_add_test(tc, is_less_5);
  tcase_add_test(tc, is_less_6);
  tcase_add_test(tc, is_less_7);
  tcase_add_test(tc, is_less_8);

  suite_add_tcase(s, tc);
  return s;
}

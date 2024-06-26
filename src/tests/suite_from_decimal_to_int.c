#include "unit_tests.h"

START_TEST(test_s21_decimal_to_int_0) {
  int test = 0;
  int result = 0;
  s21_decimal value = {{test, 0, 0, 0}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_1) {
  int test = 1;
  int result = 0;
  s21_decimal value = {{test, 0, 0, 0}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_1234567) {
  int test = 12345678;
  int result = 0;
  s21_decimal value = {{test, 0, 0, 0}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_max) {
  int test = INT_MAX;
  int result = 0;
  s21_decimal value = {{test, 0, 0, 0}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_max_1) {
  int test = 2147483647;
  int result = 0;
  s21_decimal value = {{test, 0, 0, 0}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_minus_1) {
  int test = -1;
  int result = 0;
  s21_decimal value = {{-test, 0, 0, 0x80000000}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_minus_1234567) {
  int test = -1234567;
  int result = 0;
  s21_decimal value = {{-test, 0, 0, 0x80000000}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_min_plus_1) {
  int test = INT_MIN + 1;
  int result = 0;
  s21_decimal value = {{-test, 0, 0, 0x80000000}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

END_TEST

START_TEST(test_s21_decimal_to_int_min) {
  int test = 2147483648;
  int result = 0;
  s21_decimal value = {
      {(unsigned int)2147483648, 0, 0, 0b10000000000000000000000000000000}};
  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

Suite *suite_from_decimal_to_int(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_decimal_to_int");
  tc = tcase_create("case_from_decimal_to_int");

  tcase_add_test(tc, test_s21_decimal_to_int_0);
  tcase_add_test(tc, test_s21_decimal_to_int_1);
  tcase_add_test(tc, test_s21_decimal_to_int_1234567);
  tcase_add_test(tc, test_s21_decimal_to_int_max);
  tcase_add_test(tc, test_s21_decimal_to_int_max_1);
  tcase_add_test(tc, test_s21_decimal_to_int_minus_1);
  tcase_add_test(tc, test_s21_decimal_to_int_minus_1234567);
  tcase_add_test(tc, test_s21_decimal_to_int_min_plus_1);
  tcase_add_test(tc, test_s21_decimal_to_int_min);
  suite_add_tcase(s, tc);
  return s;
}

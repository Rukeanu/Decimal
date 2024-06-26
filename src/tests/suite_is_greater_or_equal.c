#include "unit_tests.h"

START_TEST(is_greater_or_equal_1) {
  s21_decimal val1 = {{1, 0, 0, 393216}};  // 0.000001
  s21_decimal val2 = {{1, 0, 0, 196608}};  // 0.001

  ck_assert_int_eq(s21_is_greater_or_equal(val1, val2), 0);
}

START_TEST(is_greater_or_equal_2) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(val1, val2), 1);
}

START_TEST(is_greater_or_equal_3) {
  s21_decimal val1 = {{0, 0, 1, (unsigned int)-65536}};
  s21_decimal val2 = {{0, 0, 1, 65536}};

  ck_assert_int_eq(s21_is_greater_or_equal(val1, val2), 0);
}

START_TEST(is_greater_or_equal_4) {
  s21_decimal val1 = {{4, 3, 2, 0}};  // 3.6893488160304E+19
  s21_decimal val2 = {{1, 3, 4, 0}};  // 7.3786976307723E+19

  ck_assert_int_eq(s21_is_greater_or_equal(val1, val2), 0);
}

Suite *suite_is_greater_or_equal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_greater_or_equal");
  tc = tcase_create("case_greater_or_equal");

  tcase_add_test(tc, is_greater_or_equal_1);
  tcase_add_test(tc, is_greater_or_equal_2);
  tcase_add_test(tc, is_greater_or_equal_3);
  tcase_add_test(tc, is_greater_or_equal_4);
  suite_add_tcase(s, tc);
  return s;
}

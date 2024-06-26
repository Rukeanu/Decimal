#include "unit_tests.h"

START_TEST(is_equal_1) {
  s21_decimal val1 = {{0, 0, 1, 666666}};
  s21_decimal val2 = {{0, 0, 1, 777777}};

  int result = s21_is_equal(val1, val2);

  ck_assert_int_eq(result, 0);
}

START_TEST(is_equal_2) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  int result = s21_is_equal(val1, val2);

  ck_assert_int_eq(result, 1);
}

START_TEST(is_equal_3) {
  s21_decimal val1 = {{0, 0, 1, (unsigned int)-65536}};
  s21_decimal val2 = {{0, 0, 1, 65536}};

  int result = s21_is_equal(val1, val2);

  ck_assert_int_eq(result, 0);
}

START_TEST(is_equal_4) {
  s21_decimal val1 = {{4, 3, 2, 0}};  // 3.6893488160304E+19
  s21_decimal val2 = {{1, 3, 4, 0}};  // 7.3786976307723E+19

  int result = s21_is_equal(val1, val2);

  ck_assert_int_eq(result, 0);
}

START_TEST(is_equal_5) {
  s21_decimal val1 = {{0, 0, 0, (unsigned int)-2147483648}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  int result = s21_is_equal(val1, val2);

  ck_assert_int_eq(result, 1);
}

Suite *suite_is_equal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_is_equal");
  tc = tcase_create("case_is_equal");

  tcase_add_test(tc, is_equal_1);
  tcase_add_test(tc, is_equal_2);
  tcase_add_test(tc, is_equal_3);
  tcase_add_test(tc, is_equal_4);
  tcase_add_test(tc, is_equal_5);

  suite_add_tcase(s, tc);
  return s;
}

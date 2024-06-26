#include "unit_tests.h"

START_TEST(not_equal_1) {
  s21_decimal val1 = {{0, 0, 1, 393216}};
  s21_decimal val2 = {{0, 0, 1, 196608}};

  int result = s21_is_not_equal(val1, val2);

  ck_assert_int_eq(result, 1);
}

START_TEST(not_equal_2) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  int result = s21_is_not_equal(val1, val2);

  ck_assert_int_eq(result, 0);
}

START_TEST(not_equal_3) {
  s21_decimal val1 = {{0, 0, 1, (unsigned int)-65536}};
  s21_decimal val2 = {{0, 0, 1, 65536}};

  int result = s21_is_not_equal(val1, val2);

  ck_assert_int_eq(result, 1);
}

START_TEST(not_equal_4) {
  s21_decimal val1 = {{4, 3, 2, 0}};  // 3.6893488160304E+19
  s21_decimal val2 = {{1, 3, 4, 0}};  // 7.3786976307723E+19

  int result = s21_is_not_equal(val1, val2);

  ck_assert_int_eq(result, 1);
}

START_TEST(not_equal_5) {
  s21_decimal val1 = {{0, 0, 0, (unsigned int)-6699999999}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  int result = s21_is_not_equal(val1, val2);

  ck_assert_int_eq(result, 0);
}

START_TEST(not_equal_6) {
  s21_decimal val1 = {{4, 0, 0, 393216}};
  s21_decimal val2 = {{4, 0, 0, 393216}};

  int result = s21_is_not_equal(val1, val2);

  ck_assert_int_eq(result, 0);
}

Suite *suite_is_not_equal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_is_not_equal");
  tc = tcase_create("case_is_not_equal");

  tcase_add_test(tc, not_equal_1);
  tcase_add_test(tc, not_equal_2);
  tcase_add_test(tc, not_equal_3);
  tcase_add_test(tc, not_equal_4);
  tcase_add_test(tc, not_equal_5);
  tcase_add_test(tc, not_equal_6);

  suite_add_tcase(s, tc);
  return s;
}

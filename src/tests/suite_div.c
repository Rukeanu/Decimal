#include "unit_tests.h"

START_TEST(test_s21_add_1) {
  s21_decimal a, b;
  s21_from_int_to_decimal(3, &a);
  s21_from_int_to_decimal(4, &b);

  s21_decimal result;
  int error_code = s21_div(a, b, &result);
  ck_assert_int_eq(error_code, 0);

  int int_result = result.bits[0];
  s21_from_decimal_to_int(result, &int_result);
  ck_assert_int_eq(int_result, 7);
}
END_TEST

Suite *suite_div(void) {
  Suite *s = suite_create("suite_div");
  TCase *tc = tcase_create("case_div");

  tcase_add_test(tc, test_s21_add_1);

  suite_add_tcase(s, tc);
  return s;
}
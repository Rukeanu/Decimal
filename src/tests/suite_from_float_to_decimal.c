#include "unit_tests.h"

START_TEST(test_s21_from_float_to_decimal_003f) {
  s21_decimal value;
  s21_from_float_to_decimal(0.03F, &value);
  ck_assert_int_eq(value.bits[0], 3);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0b00000000000000100000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_m003f) {
  s21_decimal value;
  s21_from_float_to_decimal(-0.03F, &value);
  ck_assert_int_eq(value.bits[0], 3);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], 0b10000000000000100000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_30f) {
  s21_decimal value;
  s21_from_float_to_decimal(3.0F, &value);
  ck_assert_int_eq(value.bits[0], 3);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_0f) {
  s21_decimal value;
  s21_from_float_to_decimal(0.0F, &value);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_105f) {
  s21_decimal value;
  s21_from_float_to_decimal(10.5F, &value);
  ck_assert_int_eq(value.bits[0], 105);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 65536);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_10209f) {
  s21_decimal value;
  s21_from_float_to_decimal(1.02E+09F, &value);
  ck_assert_int_eq(value.bits[0], 1020000000);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_00002f) {
  s21_decimal value;
  s21_from_float_to_decimal(0.000000002F, &value);
  ck_assert_int_eq(value.bits[0], 2);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0b00000000000010010000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_5454) {
  s21_decimal value;
  s21_from_float_to_decimal(-5454.353F, &value);
  ck_assert_int_eq(value.bits[0], 5454353);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], 0b10000000000000110000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_m5492) {
  s21_decimal value;
  s21_from_float_to_decimal(-5.492654F, &value);
  ck_assert_int_eq(value.bits[0], 5492654);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], 0b10000000000001100000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_7961) {
  s21_decimal value;
  s21_from_float_to_decimal(7.961328E+08F, &value);
  ck_assert_int_eq(value.bits[0], 796132800);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_null_test) {
  int num = s21_from_float_to_decimal(7.961328E+08F, NULL);
  ck_assert_int_eq(1, num);
}
END_TEST

Suite *suite_from_float_to_decimal(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_float_to_decimal");
  tc = tcase_create("case_from_float_to_decimal");

  tcase_add_test(tc, test_s21_from_float_to_decimal_003f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_m003f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_30f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_0f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_105f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_10209f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_00002f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_5454);
  tcase_add_test(tc, test_s21_from_float_to_decimal_m5492);
  tcase_add_test(tc, test_s21_from_float_to_decimal_7961);
  tcase_add_test(tc, test_s21_from_float_to_decimal_null_test);

  suite_add_tcase(s, tc);
  return s;
}

#include "unit_tests.h"

START_TEST(test_s21_dec_to_float_2546_5f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 25465;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", 2546.5);
  snprintf(check_result, sizeof(result), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_m0_46453f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 46453;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b10000000000001010000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", -0.46453);
  snprintf(check_result, sizeof(check_result), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_3_5f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 35;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", 3.5);
  snprintf(check_result, sizeof(check_result), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_4_5f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 45;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", 4.5);
  snprintf(check_result, sizeof(check_result), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_m4_5f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 0b00000000000000000000000000101101;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b10000000000000010000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", -4.5);
  snprintf(check_result, sizeof(check_result), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_m5_49265f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 0b00000000000010000110000110010001;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b10000000000001010000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", -5.49265);
  snprintf(check_result, sizeof(flt2str), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_2_508f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 0b01100101111011101101100101011111;
  result.bits[1] = 0b01011100001001010100001101000110;
  result.bits[2] = 0b00000000000000000000000000000001;
  result.bits[3] = 0b00000000000100110000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", 2.50865312689741);
  snprintf(check_result, sizeof(check_result), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

Suite *suite_from_decimal_to_float(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_decimal_to_float");
  tc = tcase_create("case_from_decimal_to_float");

  tcase_add_test(tc, test_s21_dec_to_float_2546_5f);
  tcase_add_test(tc, test_s21_dec_to_float_m0_46453f);
  tcase_add_test(tc, test_s21_dec_to_float_3_5f);
  tcase_add_test(tc, test_s21_dec_to_float_4_5f);
  tcase_add_test(tc, test_s21_dec_to_float_m4_5f);
  tcase_add_test(tc, test_s21_dec_to_float_m5_49265f);
  tcase_add_test(tc, test_s21_dec_to_float_2_508f);

  suite_add_tcase(s, tc);
  return s;
}

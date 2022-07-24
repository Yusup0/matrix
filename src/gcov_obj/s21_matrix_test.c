#include "../s21_matrix.h"
#include <check.h>
#include <limits.h>

// -------------------------------------------------------

START_TEST(s21_eq_matrix_test) {
  matrix_t matrix, result;
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &result);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[1][0] = 1;
  matrix.matrix[1][1] = 2;
  matrix.matrix[1][2] = 2;
  matrix.matrix[2][0] = 1;
  matrix.matrix[2][1] = 2;
  matrix.matrix[2][2] = 2;
  result.matrix[0][0] = 1;
  result.matrix[0][1] = 2;
  result.matrix[0][2] = 2;
  result.matrix[1][0] = 1;
  result.matrix[1][1] = 2;
  result.matrix[1][2] = 2;
  result.matrix[2][0] = 1;
  result.matrix[2][1] = 2;
  result.matrix[2][2] = 2;
  ck_assert_int_eq(1, s21_eq_matrix(&matrix, &result));

  matrix.matrix[0][0] = 1.000001;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[1][0] = 1;
  matrix.matrix[1][1] = 2;
  matrix.matrix[1][2] = 2;
  matrix.matrix[2][0] = 1;
  matrix.matrix[2][1] = 2;
  matrix.matrix[2][2] = 2;
  result.matrix[0][0] = 1.000002;
  result.matrix[0][1] = 2;
  result.matrix[0][2] = 2;
  result.matrix[1][0] = 1;
  result.matrix[1][1] = 2;
  result.matrix[1][2] = 2;
  result.matrix[2][0] = 1;
  result.matrix[2][1] = 2;
  result.matrix[2][2] = 2;
  ck_assert_int_eq(0, s21_eq_matrix(&matrix, &result));

  matrix.matrix[0][0] = 1.0000001;
  matrix.matrix[0][1] = 2.0000099;
  matrix.matrix[0][2] = 2;
  matrix.matrix[1][0] = 1;
  matrix.matrix[1][1] = 2;
  matrix.matrix[1][2] = 2;
  matrix.matrix[2][0] = 1;
  matrix.matrix[2][1] = 2;
  matrix.matrix[2][2] = 2;
  result.matrix[0][0] = 1.0000006;
  result.matrix[0][1] = 2.0000091;
  result.matrix[0][2] = 2;
  result.matrix[1][0] = 1;
  result.matrix[1][1] = 2;
  result.matrix[1][2] = 2;
  result.matrix[2][0] = 1;
  result.matrix[2][1] = 2;
  result.matrix[2][2] = 2;
  ck_assert_int_eq(1, s21_eq_matrix(&matrix, &result));

  s21_remove_matrix(&result);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_sum_matrix_test) {
  matrix_t matrix, matrix1, result, summ;
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &result);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[1][0] = 1;
  matrix.matrix[1][1] = 2;
  matrix.matrix[1][2] = 2;
  matrix.matrix[2][0] = 1;
  matrix.matrix[2][1] = 2;
  matrix.matrix[2][2] = 2;
  matrix1.matrix[0][0] = 0;
  matrix1.matrix[0][1] = 0;
  matrix1.matrix[0][2] = 0;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 0;
  matrix1.matrix[1][2] = 0;
  matrix1.matrix[2][0] = 0;
  matrix1.matrix[2][1] = 0;
  matrix1.matrix[2][2] = 0;
  s21_sum_matrix(&matrix, &matrix1, &summ);
  result.matrix[0][0] = 1;
  result.matrix[0][1] = 2;
  result.matrix[0][2] = 2;
  result.matrix[1][0] = 1;
  result.matrix[1][1] = 2;
  result.matrix[1][2] = 2;
  result.matrix[2][0] = 1;
  result.matrix[2][1] = 2;
  result.matrix[2][2] = 2;
  ck_assert_int_eq(1, s21_eq_matrix(&summ, &result));
  s21_remove_matrix(&summ);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 3;
  matrix.matrix[1][0] = 4;
  matrix.matrix[1][1] = 5;
  matrix.matrix[1][2] = 6;
  matrix.matrix[2][0] = 7;
  matrix.matrix[2][1] = 8;
  matrix.matrix[2][2] = 9;
  matrix1.matrix[0][0] = 9;
  matrix1.matrix[0][1] = 8;
  matrix1.matrix[0][2] = 7;
  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 4;
  matrix1.matrix[2][0] = 3;
  matrix1.matrix[2][1] = 2;
  matrix1.matrix[2][2] = 1;
  s21_sum_matrix(&matrix, &matrix1, &summ);
  result.matrix[0][0] = 10;
  result.matrix[0][1] = 10;
  result.matrix[0][2] = 10;
  result.matrix[1][0] = 10;
  result.matrix[1][1] = 10;
  result.matrix[1][2] = 10;
  result.matrix[2][0] = 10;
  result.matrix[2][1] = 10;
  result.matrix[2][2] = 10;
  ck_assert_int_eq(1, s21_eq_matrix(&summ, &result));

  s21_remove_matrix(&result);
  s21_remove_matrix(&summ);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_sub_matrix_test) {
  matrix_t matrix, matrix1, result, sub;
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &result);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[1][0] = 1;
  matrix.matrix[1][1] = 2;
  matrix.matrix[1][2] = 2;
  matrix.matrix[2][0] = 1;
  matrix.matrix[2][1] = 2;
  matrix.matrix[2][2] = 2;
  matrix1.matrix[0][0] = 0;
  matrix1.matrix[0][1] = 0;
  matrix1.matrix[0][2] = 0;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 0;
  matrix1.matrix[1][2] = 0;
  matrix1.matrix[2][0] = 0;
  matrix1.matrix[2][1] = 0;
  matrix1.matrix[2][2] = 0;
  s21_sub_matrix(&matrix, &matrix1, &sub);
  result.matrix[0][0] = 1;
  result.matrix[0][1] = 2;
  result.matrix[0][2] = 2;
  result.matrix[1][0] = 1;
  result.matrix[1][1] = 2;
  result.matrix[1][2] = 2;
  result.matrix[2][0] = 1;
  result.matrix[2][1] = 2;
  result.matrix[2][2] = 2;
  ck_assert_int_eq(1, s21_eq_matrix(&sub, &result));
  s21_remove_matrix(&sub);

  matrix.matrix[0][0] = 4;
  matrix.matrix[0][1] = 4;
  matrix.matrix[0][2] = 4;
  matrix.matrix[1][0] = 4;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 4;
  matrix.matrix[2][0] = 4;
  matrix.matrix[2][1] = 4;
  matrix.matrix[2][2] = 4;
  matrix1.matrix[0][0] = 5;
  matrix1.matrix[0][1] = 1;
  matrix1.matrix[0][2] = 1;
  matrix1.matrix[1][0] = 1;
  matrix1.matrix[1][1] = 1;
  matrix1.matrix[1][2] = 1;
  matrix1.matrix[2][0] = 1;
  matrix1.matrix[2][1] = 1;
  matrix1.matrix[2][2] = 1;
  s21_sub_matrix(&matrix, &matrix1, &sub);
  result.matrix[0][0] = -1;
  result.matrix[0][1] = 3;
  result.matrix[0][2] = 3;
  result.matrix[1][0] = 3;
  result.matrix[1][1] = 3;
  result.matrix[1][2] = 3;
  result.matrix[2][0] = 3;
  result.matrix[2][1] = 3;
  result.matrix[2][2] = 3;
  ck_assert_int_eq(1, s21_eq_matrix(&sub, &result));

  s21_remove_matrix(&result);
  s21_remove_matrix(&sub);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_mult_number_test) {
  matrix_t matrix, result, true_matrix;
  s21_create_matrix(2, 2, &matrix);
  s21_create_matrix(2, 2, &true_matrix);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;
  s21_mult_number(&matrix, 2, &result);

  true_matrix.matrix[0][0] = 2;
  true_matrix.matrix[0][1] = 4;
  true_matrix.matrix[1][0] = 6;
  true_matrix.matrix[1][1] = 8;
  ck_assert_int_eq(1, s21_eq_matrix(&true_matrix, &result));
  s21_remove_matrix(&result);

  matrix.matrix[0][0] = 5;
  matrix.matrix[0][1] = 6;
  matrix.matrix[1][0] = -3;
  matrix.matrix[1][1] = 0;
  s21_mult_number(&matrix, 5, &result);
  true_matrix.matrix[0][0] = 25;
  true_matrix.matrix[0][1] = 30;
  true_matrix.matrix[1][0] = -15;
  true_matrix.matrix[1][1] = 0;
  ck_assert_int_eq(1, s21_eq_matrix(&true_matrix, &result));

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&true_matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test) {
  matrix_t matrix, matrix1, result, mult;
  s21_create_matrix(3, 1, &matrix);
  s21_create_matrix(1, 3, &matrix1);
  s21_create_matrix(3, 3, &result);
  matrix.matrix[0][0] = 1;
  matrix.matrix[1][0] = 4;
  matrix.matrix[2][0] = 1;
  matrix1.matrix[0][0] = 5;
  matrix1.matrix[0][1] = -1;
  matrix1.matrix[0][2] = 0;
  s21_mult_matrix(&matrix, &matrix1, &mult);
  result.matrix[0][0] = 5;
  result.matrix[0][1] = -1;
  result.matrix[0][2] = 0;
  result.matrix[1][0] = 20;
  result.matrix[1][1] = -4;
  result.matrix[1][2] = 0;
  result.matrix[2][0] = 5;
  result.matrix[2][1] = -1;
  result.matrix[2][2] = 0;
  ck_assert_int_eq(1, s21_eq_matrix(&mult, &result));
  s21_remove_matrix(&result);
  s21_remove_matrix(&mult);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix);

  s21_create_matrix(2, 3, &matrix);
  s21_create_matrix(3, 2, &matrix1);
  s21_create_matrix(2, 2, &result);
  matrix.matrix[0][0] = 5;
  matrix.matrix[0][1] = -1;
  matrix.matrix[0][2] = 3;
  matrix.matrix[1][0] = 4;
  matrix.matrix[1][1] = -1;
  matrix.matrix[1][2] = -1;
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 4;
  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[2][0] = 1;
  matrix1.matrix[2][1] = -9;
  s21_mult_matrix(&matrix, &matrix1, &mult);
  result.matrix[0][0] = 4;
  result.matrix[0][1] = -12;
  result.matrix[1][0] = -1;
  result.matrix[1][1] = 20;
  ck_assert_int_eq(1, s21_eq_matrix(&mult, &result));
  s21_remove_matrix(&result);
  s21_remove_matrix(&mult);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_transpose_test) {
  matrix_t matrix, result, true_matrix;

  s21_create_matrix(2, 2, &matrix);
  s21_create_matrix(2, 2, &true_matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;
  s21_transpose(&matrix, &result);
  true_matrix.matrix[0][0] = 1;
  true_matrix.matrix[0][1] = 3;
  true_matrix.matrix[1][0] = 2;
  true_matrix.matrix[1][1] = 4;
  ck_assert_int_eq(1, s21_eq_matrix(&true_matrix, &result));
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&true_matrix);
  s21_remove_matrix(&result);

  s21_create_matrix(2, 3, &matrix);
  s21_create_matrix(3, 2, &true_matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 3;
  s21_transpose(&matrix, &result);
  true_matrix.matrix[0][0] = 1;
  true_matrix.matrix[0][1] = 3;
  true_matrix.matrix[1][0] = 2;
  true_matrix.matrix[1][1] = 4;
  true_matrix.matrix[2][0] = 2;
  true_matrix.matrix[2][1] = 3;
  ck_assert_int_eq(1, s21_eq_matrix(&true_matrix, &result));
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&true_matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_determinant_test) {
  matrix_t matrix;
  double result, true_res;

  s21_create_matrix(2, 2, &matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;
  s21_determinant(&matrix, &result);
  true_res = -2;
  ck_assert_int_eq(1, eq_double(true_res, result));
  s21_remove_matrix(&matrix);

  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 11;
  matrix.matrix[0][1] = -23;
  matrix.matrix[0][2] = 121;
  matrix.matrix[0][3] = 321;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = -11;
  matrix.matrix[1][2] = 0;
  matrix.matrix[1][3] = -312;
  matrix.matrix[2][0] = 23;
  matrix.matrix[2][1] = 53;
  matrix.matrix[2][2] = 13;
  matrix.matrix[2][3] = -12;
  matrix.matrix[3][0] = 1;
  matrix.matrix[3][1] = 231;
  matrix.matrix[3][2] = 11;
  matrix.matrix[3][3] = -112;
  s21_determinant(&matrix, &result);
  true_res = -195001668;
  ck_assert_int_eq(1, eq_double(true_res, result));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_calc_complements_test) {
  matrix_t matrix, res, true_res;

  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &true_res);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 22;
  matrix.matrix[0][2] = 3;
  matrix.matrix[1][0] = 4;
  matrix.matrix[1][1] = 5;
  matrix.matrix[1][2] = 6;
  matrix.matrix[2][0] = 7;
  matrix.matrix[2][1] = 8;
  matrix.matrix[2][2] = 9;
  s21_calc_complements(&matrix, &res);
  true_res.matrix[0][0] = -3;
  true_res.matrix[0][1] = 6;
  true_res.matrix[0][2] = -3;
  true_res.matrix[1][0] = -174;
  true_res.matrix[1][1] = -12;
  true_res.matrix[1][2] = 146;
  true_res.matrix[2][0] = 117;
  true_res.matrix[2][1] = 6;
  true_res.matrix[2][2] = -83;
  ck_assert_int_eq(1, s21_eq_matrix(&res, &true_res));
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res);
  s21_remove_matrix(&true_res);

  s21_create_matrix(2, 2, &matrix);
  s21_create_matrix(2, 2, &true_res);
  matrix.matrix[0][0] = -14.94;
  matrix.matrix[0][1] = -28.95;
  matrix.matrix[1][0] = 894.399;
  matrix.matrix[1][1] = 41.99;
  s21_calc_complements(&matrix, &res);
  true_res.matrix[0][0] = 41.99;
  true_res.matrix[0][1] = -894.399;
  true_res.matrix[1][0] = 28.95;
  true_res.matrix[1][1] = -14.94;
  ck_assert_int_eq(1, s21_eq_matrix(&res, &true_res));
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res);
  s21_remove_matrix(&true_res);

  s21_create_matrix(4, 4, &matrix);
  s21_create_matrix(4, 4, &true_res);
  matrix.matrix[0][0] = 132;
  matrix.matrix[0][1] = 13;
  matrix.matrix[0][2] = 1;
  matrix.matrix[0][3] = 31;
  matrix.matrix[1][0] = 23;
  matrix.matrix[1][1] = 13;
  matrix.matrix[1][2] = 13;
  matrix.matrix[1][3] = 12;
  matrix.matrix[2][0] = 31;
  matrix.matrix[2][1] = 34;
  matrix.matrix[2][2] = 34536;
  matrix.matrix[2][3] = 45;
  matrix.matrix[3][0] = 767;
  matrix.matrix[3][1] = 5675;
  matrix.matrix[3][2] = 7;
  matrix.matrix[3][3] = 5675;
  s21_calc_complements(&matrix, &res);
  true_res.matrix[0][0] = 196802086;
  true_res.matrix[0][1] = -4188099085;
  true_res.matrix[0][2] = -1475941;
  true_res.matrix[0][3] = 4161502280;
  true_res.matrix[1][0] = 3527786692;
  true_res.matrix[1][1] = 25049578865;
  true_res.matrix[1][2] = 5433173;
  true_res.matrix[1][3] = -25526380702;
  true_res.matrix[2][0] = -1331896;
  true_res.matrix[2][1] = -9301781;
  true_res.matrix[2][2] = 2909101;
  true_res.matrix[2][3] = 9478204;
  true_res.matrix[3][0] = -8524118;
  true_res.matrix[3][1] = -30016792;
  true_res.matrix[3][2] = -26494;
  true_res.matrix[3][3] = 48884786;
  ck_assert_int_eq(1, s21_eq_matrix(&res, &true_res));
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res);
  s21_remove_matrix(&true_res);
}
END_TEST

START_TEST(s21_inverse_matrix_test) {
  matrix_t matrix, res, true_res;

  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &true_res);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 22;
  matrix.matrix[0][2] = 3;
  matrix.matrix[1][0] = 4;
  matrix.matrix[1][1] = 5;
  matrix.matrix[1][2] = 6;
  matrix.matrix[2][0] = 7;
  matrix.matrix[2][1] = 8;
  matrix.matrix[2][2] = 9;
  s21_inverse_matrix(&matrix, &res);
  true_res.matrix[0][0] = -0.025;
  true_res.matrix[0][1] = -1.45;
  true_res.matrix[0][2] = 0.975;
  true_res.matrix[1][0] = 0.05;
  true_res.matrix[1][1] = -0.1;
  true_res.matrix[1][2] = 0.05;
  true_res.matrix[2][0] = -0.025;
  true_res.matrix[2][1] = 1.216667;
  true_res.matrix[2][2] = -0.691667;
  ck_assert_int_eq(1, s21_eq_matrix(&res, &true_res));
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res);
  s21_remove_matrix(&true_res);
}
END_TEST

// -------------------------------------------------------

void part1_tests(TCase *tc1_1) {
  tcase_add_test(tc1_1, s21_mult_number_test);
  tcase_add_test(tc1_1, s21_eq_matrix_test);
  tcase_add_test(tc1_1, s21_sum_matrix_test);
  tcase_add_test(tc1_1, s21_sub_matrix_test);
  tcase_add_test(tc1_1, s21_mult_matrix_test);
  tcase_add_test(tc1_1, s21_transpose_test);
  tcase_add_test(tc1_1, s21_determinant_test);
  tcase_add_test(tc1_1, s21_calc_complements_test);
  tcase_add_test(tc1_1, s21_inverse_matrix_test);
}

// -------------------------------------------------------

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);

  part1_tests(tc1_1);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

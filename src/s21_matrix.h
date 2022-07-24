#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int size_eq_matrix(matrix_t *A, matrix_t *B);
void printf_matrix(matrix_t *A);
int eq_double(double num1, double num2);
double final_matrix(matrix_t *A);
void new_matrix_determinant(matrix_t* A, matrix_t* new_matrix, int number_column, int number_row);
double determinant(matrix_t *A);
void del_number_matrix(double determinant, matrix_t *A);
int s21_isnan(double x);
int s21_isinf(double x);
int corrext_matrix(matrix_t *A);

#endif  // SRC_S21_MATRIX_H_

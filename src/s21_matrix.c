#include "./s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int back = 0;
    double determinant = 0;
    if (corrext_matrix(A))
        back = 1;
    if (!back) {
        back = s21_determinant(A, &determinant);
        if (!back && eq_double(determinant, 0))
            back = 2;
        if (!back) {
            matrix_t matrix;
            s21_calc_complements(A, &matrix);
            s21_transpose(&matrix, result);
            del_number_matrix(determinant, result);
            s21_remove_matrix(&matrix);
        }
    }
    return back;
}

void del_number_matrix(double determinant, matrix_t *A) {
    for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++)
            A->matrix[i][j] =  A->matrix[i][j] / determinant;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int back = 0;
    if (corrext_matrix(A))
        back = 1;
    if (!back && A->rows == A->columns) {
        double res_deter = 0;
        int minus = 1;
        matrix_t matrix;
        s21_create_matrix(A->rows, A->rows, result);
        s21_create_matrix(A->rows - 1, A->rows - 1, &matrix);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->rows; j++) {
                new_matrix_determinant(A, &matrix, i, j);
                s21_determinant(&matrix, &res_deter);
                minus = (i + j) % 2 == 0 ? 1 : -1;
                result->matrix[i][j] = res_deter * minus;
            }
        }
        s21_remove_matrix(&matrix);
    } else {
        back = 2;
    }
    return back;
}

int s21_determinant(matrix_t *A, double *result) {
    int back = 0;
    if (corrext_matrix(A))
        back = 1;
    if (!back && A->rows == A->columns) {
        *result = determinant(A);
    } else {
        back = 2;
    }
    return back;
}

double determinant(matrix_t *A) {
    double res = 0;
    if (A->rows < 3) {
        res = final_matrix(A);
    } else {
        int minus = 1;
        matrix_t new_matrix;
        s21_create_matrix(A->rows - 1, A->rows - 1, &new_matrix);
        for (int i = 0; i < A->columns; i++) {
            new_matrix_determinant(A, &new_matrix, 0, i);
            res += A->matrix[0][i] * determinant(&new_matrix) * minus;
            minus *= -1;
        }
        s21_remove_matrix(&new_matrix);
    }
    return res;
}

void new_matrix_determinant(matrix_t* A, matrix_t* new_matrix, int number_column, int number_row) {
    int pos_row = 0, pos_column = 0;
    for (int i = 0; i < new_matrix->rows; i++) {
        if (number_column <= i)
            pos_column = 1;
        for (int j = 0; j < new_matrix->columns; j++) {
            if (number_row <= j)
                pos_row = 1;
            new_matrix->matrix[i][j] = A->matrix[i + pos_column][j + pos_row];
        }
        pos_row = 0;
    }
}

double final_matrix(matrix_t *A) {
    double res = 0;
    if (A->rows == 2) {
       res = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else if (A->rows == 1) {
        res = A->matrix[0][0];
    }
    return res;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
    int back = 0;
    if (corrext_matrix(A))
        back = 1;
    if (!back) {
        s21_create_matrix(A->columns, A->rows, result);
        for (int i = 0; i < A->columns; i++) {
            for (int j = 0; j < A->rows; j++) {
                result->matrix[i][j] = A->matrix[j][i];
            }
        }
    }
    return back;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int back = 0;
    if (rows > 0 && columns > 0) {
        result->rows = rows;
        result->columns = columns;
         if (!(result->matrix = malloc(rows * sizeof(double*))))
            exit(13);
        for (int i = 0; i < rows; i++)
            if (!(result->matrix[i] = malloc(columns * sizeof(double))))
                exit(13);
    } else {
        back = 1;
    }
    return back;
}

void s21_remove_matrix(matrix_t *A) {
    if (A->matrix != NULL) {
        for (int i = 0; i < A->rows; i++)
            free(A->matrix[i]);
        free(A->matrix);
    }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int result = 1;
    if (size_eq_matrix(A, B)) {
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                if (!eq_double(A->matrix[i][j], B->matrix[i][j])) {
                    result = 0;
                    break;
                }
    } else {
        result = 0;
    }
    return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int back = 0;
    if (corrext_matrix(A) || corrext_matrix(B))
        back = 1;
    if (!back && size_eq_matrix(A, B)) {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    } else {
        back = 2;
    }
    return back;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int back = 0;
    if (corrext_matrix(A) || corrext_matrix(B))
        back = 1;
    if (!back && size_eq_matrix(A, B)) {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    } else {
        back = 2;
    }
    return back;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int back = 0;
    if (corrext_matrix(A))
        back = 1;
    if (!back && !s21_isnan(number) && !s21_isinf(number)) {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                result->matrix[i][j] = A->matrix[i][j] * number;
    } else {
        back = 2;
    }
    return back;
}

int corrext_matrix(matrix_t *A) {
    int back = 0;
    if (!A || A->matrix == NULL || A->rows < 1 || A->columns < 1)
        back = 1;
    return back;
}


int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int back = 0;
    double summ = 0;
    if (corrext_matrix(A) || corrext_matrix(B))
        back = 1;
    if (!back && A->columns == B->rows) {
        s21_create_matrix(B->columns, A->rows, result);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
                for (int k = 0; k < A->columns; k++) {
                    summ += A->matrix[i][k] * B->matrix[k][j];
                }
                result->matrix[i][j] = summ;
                summ = 0;
            }
        }
    } else {
        back = 2;
    }
    return back;
}

int size_eq_matrix(matrix_t *A, matrix_t *B) {
    return A->columns == B->columns && A->rows == B->rows;
}

int eq_double(double num1, double num2) {
    return fabs(num1 - num2) < 1e-6;
}

int s21_isnan(double x) { return x != x; }

int s21_isinf(double x) { return !s21_isnan(x) && s21_isnan(x - x); }

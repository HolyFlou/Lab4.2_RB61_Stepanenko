#include "funcs.h"

int** memory_allocation(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return NULL;

    int **matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) return NULL;

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        // Якщо не вдалося виділити пам'ять для одного з рядків, звільняємо попередні
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

void clearMemory(int** matrix, int rows) {
    if (matrix == NULL) return;

    for (int i = 0; i < rows; i++) {
        if (matrix[i] != NULL) {
            free(matrix[i]);
        }
    }

    free(matrix);
}

void max_min(int** A, int r_a, int* max_a, int* min_a) {
    if (A == NULL || max_a == NULL || min_a == NULL || r_a <= 1) {
        return;
    }

    int first = 1;

    for (int i = 1; i < r_a; i++) {
        for (int j = 0; j < i; j++) {
            int current = A[i][j];
            
            if (first) {
                *max_a = current;
                *min_a = current;
                first = 0;
            } else {
                if (current > *max_a)
                    *max_a = current;
                if (current < *min_a)
                    *min_a = current;
            }
        }
    }
}

int** transpose(int** B, int r_b, int c_b) {
    if (B == NULL || r_b <= 0 || c_b <= 0) return NULL;

    int** transposed = memory_allocation(c_b, r_b);
    if (transposed == NULL) return NULL;

    for (int i = 0; i < c_b; i++) {
        for (int j = 0; j < r_b; j++) {
            transposed[i][j] = B[j][i];
        }
    }

    return transposed;
}

int** mult_a_b(int ** B, int r_b, int c_b, int ** A, int r_a, int c_a) {
    // Множення B * A можливе тільки якщо c_b == r_a
    if (B == NULL || A == NULL || c_b != r_a || r_b <= 0 || c_b <= 0 || c_a <= 0) {
        return NULL;
    }

    int** result = memory_allocation(r_b, c_a);
    if (result == NULL) return NULL;

    for (int i = 0; i < r_b; i++) {
        for (int j = 0; j < c_a; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c_b; k++) {
                result[i][j] += B[i][k] * A[k][j];
            }
        }
    }

    return result;
}
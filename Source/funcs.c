#include "funcs.h"

int** memory_аllocation(int rows, int cols) {
    int i = 0;

    int **matrix = (int**)malloc(rows* sizeof(int*));

    for( i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols* sizeof(int));
    }

    printf("\nМатриця створена");
    return matrix;
}

void clearMemory( int** matrix, int rows ) {
    int i;

    for( i = 0; i < rows; i++ ) {
        free(matrix[i]);
    }

    free(matrix);
    printf("\nПам'ять очищена");
}

void max_min( int** A, int r_a, int* max_a , int* min_a ) {
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
    printf("\nmax_a: %d\nmin_a: %d", *max_a, *min_a);
}
#include "funcs.h"

int** memory_аllocation (int rows, int cols) {
    int i = 0;

    int **matrix = (int**)malloc(rows* sizeof(int*));

    for( i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols* sizeof(int));
    }

    return matrix;
}

void clearMemory ( int** matrix, int rows ) {
    int i;

    for( i = 0; i < rows; i++ ) {
        free(matrix[ i ]);
    }

    free(matrix);
}
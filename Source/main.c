#include <stdio.h>
#include <windows.h>

#include "funcs.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int rows_A = 3;
    int cols_A = 4;
    int rows_B = 4;
    int cols_B = 3;
    int num = 0;

    //Виділення пам'яті та ініціалізація матриці A
    printf("\narr_A:");
    int** arr_A = memory_аllocation(rows_A, cols_A);
    if (arr_A == NULL) {
        printf("\nПомилка виділення пам'яті для arr_A!");
        return 1;
    }
    
    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < cols_A; j++) {
            arr_A[i][j] = num;
            num++;
        }
    }
    printf("\nМатриця A успішно створена");

    //Виділення пам'яті та ініціалізація матриці B
    printf("\n\narr_B:");
    int** arr_B = memory_аllocation(rows_B, cols_B);
    if (arr_B == NULL) {
        printf("\nПомилка виділення пам'яті для arr_B!");
        clearMemory(arr_A, rows_A);
        return 1;
    }
    
    for (int i = 0; i < rows_B; i++) {
        for (int j = 0; j < cols_B; j++) {
            arr_B[i][j] = num;
            num--;
        }
    }
    printf("\nМатриця B успішно створена\n");

    //Пошук мінімуму та максимуму
    int max = 0;
    int min = 0;

    max_min(arr_A, rows_A, &max, &min);
    printf("\narr_A -> Max: %d, Min: %d", max, min);

    max_min(arr_B, rows_B, &max, &min);
    printf("\narr_B -> Max: %d, Min: %d\n", max, min);

    //Транспонування матриці B
    printf("\nТранспонована матриця B (%dx%d)\n", cols_B, rows_B);
    int** transposed_B = transpose(arr_B, rows_B, cols_B);

    for (int i = 0; i < cols_B; i++) {
        for (int j = 0; j < rows_B; j++) {
            printf("%2d ", transposed_B[i][j]);
        }
        printf("\n");
    }

    //Множення матриць B * A
    printf("\nМноження B * A (%dx%d)\n", rows_B, cols_A);
    int** a_b = mult_a_b(arr_B, rows_B, cols_B, arr_A, rows_A, cols_A);

    for (int i = 0; i < rows_B; i++) {
        for (int j = 0; j < cols_A; j++) {
            printf("%4d ", a_b[i][j]);
        }
        printf("\n");
    }

    //Очищення всієї динамічно виділеної пам'яті
    clearMemory(arr_A, rows_A);
    clearMemory(arr_B, rows_B);
    clearMemory(transposed_B, cols_B);
    clearMemory(a_b, rows_B);

    return 0;
}
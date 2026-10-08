#include <stdio.h>
#include <windows.h>

#include "funcs.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int rows_A = 0, cols_A = 0, rows_B = 0, cols_B = 0;

    //Ввід та створення матриці A
    printf("Введіть кількість рядків в матриці A: ");
    scanf("%d", &rows_A);

    printf("Введіть кількість стовпців в матриці A: ");
    scanf("%d", &cols_A);

    int** arr_A = memory_allocation(rows_A, cols_A);
    if (arr_A == NULL) {
        printf("\nПомилка виділення пам'яті для arr_A!");
        return 1;
    }

    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < cols_A; j++) {
            printf("Введіть число для A[%d][%d]: ", i, j);
            scanf("%d", &arr_A[i][j]);
        }
    }
    printf("\nМатриця A успішно створена\n\n");

    //Ввід та створення матриці B
    printf("Введіть кількість рядків в матриці B: ");
    scanf("%d", &rows_B);

    printf("Введіть кількість стовпців в матриці B: ");
    scanf("%d", &cols_B);

    int** arr_B = memory_allocation(rows_B, cols_B);
    if (arr_B == NULL) {
        printf("\nПомилка виділення пам'яті для arr_B!");
        clearMemory(arr_A, rows_A);
        return 1;
    }

    for (int i = 0; i < rows_B; i++) {
        for (int j = 0; j < cols_B; j++) {
            printf("Введіть число для B[%d][%d]: ", i, j);
            scanf("%d", &arr_B[i][j]);
        }
    }
    printf("\nМатриця B успішно створена\n");

    system("cls");

    while (1) {
        int choice = 0;
        printf("\nОберіть операцію:");
        printf("\n1: Мінімум та максимум матриці A (під діагоналлю)");
        printf("\n2: Мінімум та максимум матриці B (під діагоналлю)");
        printf("\n3: Транспонування матриці A");
        printf("\n4: Транспонування матриці B");
        printf("\n5: Множення матриць A * B");
        printf("\n6: Множення матриць B * A");
        printf("\n0: Закрити програму");
        printf("\nВаш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int max = 0, min = 0;
                max_min(arr_A, rows_A, &max, &min);
                printf("\narr_A -> Max: %d, Min: %d\n", max, min);
                break;
            }
            case 2: {
                int max = 0, min = 0;
                max_min(arr_B, rows_B, &max, &min);
                printf("\narr_B -> Max: %d, Min: %d\n", max, min);
                break;
            }
            case 3: {
                printf("\nТранспонована матриця A (%dx%d):\n", cols_A, rows_A);
                int** transposed_A = transpose(arr_A, rows_A, cols_A);
                if (transposed_A != NULL) {
                    for (int i = 0; i < cols_A; i++) {
                        for (int j = 0; j < rows_A; j++) {
                            printf("%3d ", transposed_A[i][j]);
                        }
                        printf("\n");
                    }
                    clearMemory(transposed_A, cols_A);
                }
                break;
            }
            case 4: {
                printf("\nТранспонована матриця B (%dx%d):\n", cols_B, rows_B);
                int** transposed_B = transpose(arr_B, rows_B, cols_B);
                if (transposed_B != NULL) {
                    for (int i = 0; i < cols_B; i++) {
                        for (int j = 0; j < rows_B; j++) {
                            printf("%3d ", transposed_B[i][j]);
                        }
                        printf("\n");
                    }
                    clearMemory(transposed_B, cols_B);
                }
                break;
            }
            case 5: {
                int** a_b = mult_a_b(arr_A, rows_A, cols_A, arr_B, rows_B, cols_B);
                if (a_b == NULL) {
                    printf("\nПомилка: Множення A * B неможливе! (Cols_A != Rows_B)\n");
                } else {
                    printf("\nРезультат A * B (%dx%d):\n", rows_A, cols_B);
                    for (int i = 0; i < rows_A; i++) {
                        for (int j = 0; j < cols_B; j++) {
                            printf("%4d ", a_b[i][j]);
                        }
                        printf("\n");
                    }
                    clearMemory(a_b, rows_A);
                }
                break;
            }
            case 6: {
                int** b_a = mult_a_b(arr_B, rows_B, cols_B, arr_A, rows_A, cols_A);
                if (b_a == NULL) {
                    printf("\nПомилка: Множення B * A неможливе! (Cols_B != Rows_A)\n");
                } else {
                    printf("\nРезультат B * A (%dx%d):\n", rows_B, cols_A);
                    for (int i = 0; i < rows_B; i++) {
                        for (int j = 0; j < cols_A; j++) {
                            printf("%4d ", b_a[i][j]);
                        }
                        printf("\n");
                    }
                    clearMemory(b_a, rows_B);
                }
                break;
            }
            case 0:
                clearMemory(arr_A, rows_A);
                clearMemory(arr_B, rows_B);
                printf("\nПам'ять очищена. Програму завершено.\n");
                return 0;

            default:
                printf("\nНевірний вибір операції!\n");
                break;
        }
    }

    return 0;
}
#include <stdio.h>
#include <windows.h>

#include "funcs.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int rows = 3;
    int cols = 3;

    int** arr = memory_аllocation(rows, cols);

    arr[0][0] = 5;  arr[0][1] = 3;  arr[0][2] = 4;
    arr[1][0] = 10; arr[1][1] = 2;  arr[1][2] = 5;
    arr[2][0] = 1;  arr[2][1] = 0;  arr[2][2] = 20;


    int max = 0;
    int min = 0;

    max_min(arr, rows, &max, &min);

    clearMemory(arr, rows);
    return 0;
}
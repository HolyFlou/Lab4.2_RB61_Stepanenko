#ifndef FUNCS_H
#define FUNCS_H
#include <stdio.h>
#include <stdlib.h>

int ** memory_аllocation ( int rows, int cols );
void clearMemory ( int ** matrix, int rows );
void мax_min ( int ** A, int r_a, int * max_a , int * min_a );
int ** transpose ( int ** B, int r_b, int m_b );
int ** mult_a_b ( int ** B, int r_b, int c_b, int ** A, int r_a );

#endif // FUNCS_H
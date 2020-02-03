#include<stdio.h>
#define ROWS 3
#define COLUMNS 5
void copy_vla(int row, int col, double source[row][col], double target[row][col]);
void put_vla(int row, int col, double ar[row][col]);
int main(void)
{
    double source[ROWS][COLUMNS] =
    {
        {1.56,2.36,2.78,1.69,3.56},
        {3.65,5.69,2.36,8.69,1.63},
        {8.69,1.36,5.14,6.21,3.25}
    };
    double target[ROWS][COLUMNS];
 
    printf("source=\n");
    put_vla(ROWS, COLUMNS, source);
    copy_vla(ROWS, COLUMNS, source, target);
    printf("\ntarget=\n");
    put_vla(ROWS, COLUMNS, target);
 
    return 0;
}
 
void copy_vla(int row, int col, double source[row][col], double target[row][col])
{
    int r, c;
 
    for (r = 0; r < row; r++)
        for (c = 0; c < col; c++)
            target[r][c] = source[r][c];
}
 
void put_vla(int row, int col, double ar[row][col])
{
    double(*pr)[col];
    double* pc;
 
    for (pr = ar; pr < ar + row; pr++)
    {
        for (pc = *pr; pc < *pr + col; pc++)
            printf("%.2f ", *pc);
        putchar('\n');
    }
}

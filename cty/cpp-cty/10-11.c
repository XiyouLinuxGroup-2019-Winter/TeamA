#include<stdio.h>
#define ROWS 3
#define COLUMNS 5
void doub(int ar[][COLUMNS], int n);
void put_array(int ar[][COLUMNS], int n);
int main(void)
{
    int arr[ROWS][COLUMNS] =
    {
    {1 ,2 ,3 ,4 ,5 },
    {6 ,7 ,8 ,9 ,10},
    {11,12,13,14,15}
    };
 
    printf("Original array=\n");
    put_array(arr, ROWS);
    doub(arr, ROWS);
    printf("\nCurrent array=\n");
    put_array(arr, ROWS);
 
    return 0;
}
 
void doub(int ar[][COLUMNS], int n)
{
    int(*pr)[COLUMNS];
    int* pc;
 
    for (pr = ar; pr < ar + n; pr++)
        for (pc = *pr; pc < *pr + COLUMNS; pc++)
            *pc *= 2;
}
 
void put_array(int ar[][COLUMNS], int n)
{
    int(*pr)[COLUMNS];
    int* pc;
 
    for (pr = ar; pr < ar + n; pr++)
    {
        for (pc = *pr; pc < *pr + COLUMNS; pc++)
            printf("%d ",*pc);
        putchar('\n');
    }
}

#include<stdio.h>
#define LENGTH 4
void add_per(int* source1, int* source2, int* target, int n);
void put_array(int* ar, int n);
int main(void)
{
    int source1[LENGTH] = { 1,2,3,4 };
    int source2[LENGTH] = { 1,2,3,4 };
    int target[LENGTH];
 
    printf("source1= ");
    put_array(source1, LENGTH);
    printf("\nsource2= ");
    put_array(source2, LENGTH);
    add_per(source1, source2, target, LENGTH);
    printf("\n\ntarget= ");
    put_array(target, LENGTH);
    putchar('\n');
 
    return 0;
}
 
void add_per(int* source1, int* source2, int* target, int n)
{
    int i;
 
    for (i = 0; i < n; i++)
        target[i] = source1[i] + source2[i];
}
 
void put_array(int* ar, int n)
{
    int* p;
 
    for (p = ar; p < ar + n; p++)
        printf("%d ", *p);
}

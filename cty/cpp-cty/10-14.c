#include<stdio.h>
#define ROWS 3
#define COLUMNS 5
void get_array(int rows,int cols,double ar[rows][cols]);
double per_average(double* ar, int n);
double tot_average(double* ave, int n);
double max_array(int rows,int cols,double ar[rows][cols]);
void put_result(double* ave, int n, double ave_tot, double max);
int main(void)
{
    double arr[ROWS][COLUMNS];
    double ave[3], ave_tot;
    double max;
    int i;
 
    printf("Please enter three groups decimals,each for five.\n");
    get_array(ROWS,COLUMNS,arr);
    for (i = 0; i < ROWS; i++)
        ave[i] = per_average(arr[i], COLUMNS);
    ave_tot = tot_average(ave, ROWS);
    max = max_array(ROWS,COLUMNS,arr);
    printf("\nResult:\n");
    put_result(ave, ROWS, ave_tot, max);
 
    return 0;
}
 
void get_array(int rows,int cols,double ar[rows][cols])
{
    double(*pr)[COLUMNS];
    double* pc;
 
    for (pr = ar; pr < ar + rows; pr++)
        for (pc = *pr; pc < *pr + cols; pc++)
            scanf("%lf", pc);
}
 
double per_average(double* ar, int n)
{
    double* p;
    double total = 0;
 
    for (p = ar; p < ar + n; p++)
        total += *p;
    return total / n;
}
 
double tot_average(double* ave, int n)
{
    double* p;
    double total = 0;
 
    for (p = ave; p < ave + n; p++)
        total += *p;
    return total / n;
}
 
double max_array(int rows,int cols,double ar[rows][cols])
{
    double(*pr)[COLUMNS];
    double* pc;
    double max = 0;
 
    for (pr = ar; pr < ar + rows; pr++)
        for (pc = *pr; pc < *pr + cols; pc++)
        {
            if (*pc > max)
                max = *pc;
        }
    return max;
}
 
void put_result(double* ave, int n, double ave_tot, double max)
{
    double* p;
 
    printf(" GROUP   AVERAGE\n");
    for (p = ave; p < ave + n; p++)
        printf("%4d %10.2f\n", p - ave + 1, *p);
    printf("Average of all data: %.2f\n", ave_tot);
    printf("Maximum value of all data: %.2f\n", max);
}

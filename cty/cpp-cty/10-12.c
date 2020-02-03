#include<stdio.h>
#define YEARS 5
#define MONTHS 12
float year_rain(const float ar[][MONTHS], int n);
void month_rain(const float ar[][MONTHS], int n);
int main(void)
{
    const float rain[YEARS][MONTHS] =
    {
    {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
    {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
    {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
    {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
    {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };
    float total;
 
    printf(" YEAR   RAINFALL  (inches)\n");
    total = year_rain(rain,YEARS);
    printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jun  Aug  Sep  Oct  Nov  Dec\n");
    month_rain(rain, YEARS);
 
    return 0;
}
 
float year_rain(const float ar[][MONTHS], int n)
{
    const float(*pr)[MONTHS];
    const float* pc;
    float subtot, total;
 
    for (pr = ar, total = 0; pr < ar + n; pr++)
    {
        for (pc = *pr, subtot = 0; pc < *pr + MONTHS; pc++)
            subtot += *pc;
        printf("%5d %15.1f\n", 2010 + (pr - ar), subtot);
        total += subtot;
    }
    return total;
}
 
void month_rain(const float ar[][MONTHS], int n)
{
    const float(*pr)[MONTHS];
    const float* pc;
    float subtot;
 
    for (pc = *ar; pc < *ar + MONTHS; pc++)
    {
        for (pr = ar, subtot = 0; pr < ar + n; pr++)
            subtot += *((*pr) + (pc - *ar));
        printf("%4.1f ", subtot / YEARS);
    }
    putchar('\n');
}

#include<stdio.h>
 
void set_mode(int n,int *mod,int *last)
{
    if (n > 1)
    {
        printf("Invalid mode specified. Mode %s used.\n",
            *last == 1 ? "1(US)" : "0(metric)");
        *mod = *last;
    }
    else
    {
        *mod = n;
        *last = n;
    }
}
 
void get_info(int mod,float *fuel,float *distance)
{
    if (mod == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        while (!scanf_s("%f", distance))
        {
            while (getchar() != '\n')
                continue;
            printf("Please enter digit: ");
        }
        printf("Enter fuel consumed in liters: ");
        while (!scanf_s("%f", fuel))
        {
            while (getchar() != '\n')
                continue;
            printf("Please enter digit: ");
        }
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        while (!scanf_s("%f", distance))
        {
            while (getchar() != '\n')
                continue;
            printf("Please enter digit: ");
        }
        printf("Enter fuel consumed in gallons: ");
        while (!scanf_s("%f", fuel))
        {
            while (getchar() != '\n')
                continue;
            printf("Please enter digit: ");
        }
    }
}
 
void show_info(int mod,float fuel,float distance)
{
    if (mod == 0)
        printf("Fuel consumption is %.2f liters per 100km.\n",
            fuel / (distance / 100));
    else
        printf("Fuel consumption is %.1f miles per gallon.\n",
            distance / fuel);
}

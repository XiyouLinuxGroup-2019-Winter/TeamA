#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    double result = 1.0;
    double base;
    int pow;
 
    if(argc==3)
    {
        base=atof(argv[1]);
        pow=atoi(argv[2]);
        for (; pow > 0; pow--)
            result *= base;
        printf("Result= %f\n", result);
    }
    else
        printf("The parameter is incorrect.\n");
 
    return 0;
}

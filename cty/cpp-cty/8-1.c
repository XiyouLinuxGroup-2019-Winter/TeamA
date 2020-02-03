#include<stdio.h>
int main(void)
{
    unsigned int count = 0;
    char ch;
 
    printf("Please enter some text.(end with EOF)\n");
    while ((ch = getchar()) != EOF)
        count++;
    printf("This file has %u characters.\n", count);
 
    return 0;
}

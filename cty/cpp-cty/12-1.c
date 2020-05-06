#include<stdio.h>
void critic(int* p);
int main(void)
{
    int units;
 
    printf("How many pounds to a firkin of butter?\n");
    scanf_s("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must have looked it up!\n");
 
    return 0;
}
 
void critic(int* p)
{
    printf("No luck,my friend.Try again.\n");
    scanf_s("%d", p);
}

#include<stdio.h>
#include<string.h>
int main(void)
{
char array[255];
int i=0;
printf("Please enter a line of characters.\n");
scanf("%c", &array[i], 1);
while (array[i] != '\n')
{
i++;
scanf("%c", &array[i], 1);
}
for (i--; i >= 0; i--)
printf("%c", array[i]);
printf("\n");
return 0;
}

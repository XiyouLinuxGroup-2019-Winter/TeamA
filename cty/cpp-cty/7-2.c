#include<stdio.h>
int main(void)
{
char ch;
unsigned int count = 0;
printf("Please enter some text.(end with #)\n");
while ((ch = getchar()) != '#')
{
if (ch == '\n')
continue;
printf("%4c-%-4hhu ",ch,ch);
count++;
if (count % 8 == 0)
putchar('\n');
}
printf("\n");
return 0;
}

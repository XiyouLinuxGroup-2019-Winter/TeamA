#include<stdio.h>
int main(void)
{
char ch;
unsigned int count = 0;
printf("Please enter some text.(end with #)\n");
while ((ch = getchar()) != '#')
{
if (ch == '.')
{
ch = '!';
count++;
}
else if (ch == '!')
{
putchar(ch);
count++;
}
putchar(ch);
}
printf("\nA total of %u replacements.\n", count);
return 0;
}

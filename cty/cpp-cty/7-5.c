#include<stdio.h>
int main(void)
{
char ch;
unsigned int count = 0;
printf("Please enter some text.(end with #)\n");
while ((ch = getchar()) != '#')
{
switch (ch)
{
case '.':
ch = '!';
count++;
break;
case '!':
putchar(ch);
count++;
break;
default: break;
}
putchar(ch);
}
printf("\nA total of %u replacements.\n", count);
return 0;
}
 

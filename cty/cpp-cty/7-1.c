#include<stdio.h>
int main(void)
{
char ch;
unsigned int s_count = 0;
unsigned int l_count = 0;
unsigned int o_count = 0;
printf("Please enter some text.(end with #)\n");
while ((ch = getchar()) != '#')
{
if (ch == ' ')
s_count++;
else if (ch == '\n')
l_count++;
else
o_count++;
}
printf("The number of spaces is %d\n", s_count);
printf("The number of newline characters is %d\n", l_count);
printf("The number of other characters is %d\n", o_count);
return 0;
}

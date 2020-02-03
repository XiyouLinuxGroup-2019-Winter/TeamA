#include<stdio.h>
int main(void)
{
char ch;
char ch_pre = 0;
unsigned int count = 0;
printf("Please enter some text.\n");
while ((ch = getchar()) != '#')
{
if (ch == 'e')
ch_pre = ch;
if (ch_pre == 'e' && ch == 'i')
count++;
}
printf("The count of 'ei' is %u\n", count);
return 0;
}
 


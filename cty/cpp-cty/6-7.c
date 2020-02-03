#include<stdio.h>
#include<string.h>
int main(void)
{
char word[30];
int length;
int i;
printf("Please enter a word.\n");
scanf("%s", word, 30);
length = strlen(word);
for (i = length - 1; i >= 0; i--)
printf("%c", word[i]);
printf("\n");
return 0;
}
 

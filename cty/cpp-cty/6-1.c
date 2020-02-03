#include<stdio.h>

int main(void)
{
char alphabet[26];
char letter;
int i;
for (i = 0, letter='a'; i < 26; i++ , letter++)
{
alphabet[i] = letter;
printf("%c", alphabet[i]);
}
printf("\n");
return 0;
}

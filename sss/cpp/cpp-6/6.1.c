#include <stdio.h>
int main()
{
	char a[26];
	int i,j,k,n;
	a[0]='a';
	for(i=1;i<26;i++)
		a[i]=a[i-1]+1;
	for(i=0;i<26;i++)
		printf("%c",a[i]);
}


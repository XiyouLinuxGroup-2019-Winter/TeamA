#include <stdio.h> 
int main()
{
	int i,j,k;
	char ch;
	char a[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	scanf("%c",&ch);
	for(i=0;i<=ch-65;i++)
	{
		for(j=0;j<ch-65-i;j++)
		printf(" ");
		for(j=0;j<=i;j++)
		printf("%c",a[j]);
		for(k=i-1;k>=0;k--)
		printf("%c",a[k]);
		printf("\n");
	}
}



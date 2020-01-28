#include <stdio.h>
int main()
{
	int i,j,k;
	for(i=1;i<=6;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%c",'F'+1-j);
		}
		printf("\n");
	}
}


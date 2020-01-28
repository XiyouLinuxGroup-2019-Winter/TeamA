#include <stdio.h>
int main()
{
	int i,I,j,J,k,t,T;
	char p,q;
	scanf("%c",&p);
        I=(int)(p-'A'+1);
	for(i=1;i<=I;i++)
	{
		q='A';
		J=I-i;
		for(j=1;j<=J;j++)
			printf(" ");
	        for(k=1;k<=i;k++)
			printf("%c",q++);
		q=q-1;
		T=(int)(q-'A');
		for(t=1;t<=T;t++)
			printf("%c",--q);
		printf("\n");
	}
}


	


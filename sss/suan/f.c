#include <stdio.h>
int main()
{
	char a[100];
	int m,i,j,k,n;
	scanf("%d",&m);
	getchar();
	for(j=1;j<=m;j++)
	{

	        n=0;k=0;
	while((a[n]=getchar())!='\n')
		n++;
	for(i=0;i<n;i++)
	 {
		if(a[i]>='0'&&a[i]<='9')
			k++;
	}
	printf("%d\n",k);
	}
}


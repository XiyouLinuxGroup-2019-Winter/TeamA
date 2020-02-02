#include <stdio.h>
int main()
{
	char a[1000];
	int n=0;
	while((a[n]=getchar())!='#')
		n++;
	int i,j=0;
	if(a[0]=='e'&&a[1]=='i'&&a[2]==' ')
	        j++;	
	for(i=0;i<n-3;i++)
	{
		if(a[i]==' '&&a[i+1]=='e'&&a[i+2]=='i'&&a[i+3]==' ')
			j++;
	}
	printf("%d",j);
}


		


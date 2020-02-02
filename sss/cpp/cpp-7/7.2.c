#include <stdio.h>
#include <string.h>
int main()
{
	 int i;
	 char a[1000];
	 int n;
	 n=0;
	 while((a[n]=getchar())!='#')
		 n++;
	 for(i=0;i<n;i++)
	 {
		 printf("%c-%d",a[i],a[i]);
		 if((i+1)%8==0)
			 printf("\n");
	 }
}


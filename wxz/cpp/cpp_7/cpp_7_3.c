#include <stdio.h>
#define stop '0'
int main()
{
	int n;
	int evenaver=0,oddaver=0;
	int count1=0,count2=0;
	int sumeven=0,sumodd=0;
	while((n=getchar())!=stop)
	{
		
		if(n=='\n')
		continue;
		n=n-48;
		//count1=0,count2=0;
		//sumodd=0;
		//sumeven=0;
		//evenaver=0,oddaver=0;
		if(n%2==0)
		{
			count1++;
			sumeven+=n;
			evenaver=sumeven/count1;
		}
		else
		{
			count2++;
			sumodd+=n;
			oddaver=sumodd/count2;
		}
	}
	printf("%d %d\n",count1,evenaver);
	printf("%d %d\n",count2,oddaver);
}

#include <stdio.h>
#define stop '0'
int  main()
{
	int n;
	int count1,count2;
	int sumeven=0,sumodd=0;
	double evenaver,oddaver;
	while(scanf("%d",&n)==1 && n!=0)
	{
		sumeven=0;
		sumodd=0;
		switch(n%2)
		{
			case 0:
			count1++;
			sumeven+=n;
			evenaver=sumeven/count1;
			break;
			case 1:
			count2++;
			sumodd+=n;
			oddaver=sumodd/count2;
			break;
		}
	}
	printf("%d %f\n",count1,evenaver);
	printf("%d %f\n",count2,oddaver);
}

#include <stdio.h>
#include <ctype.h>
int main()
{
	char ch;
	int count1=0,count2=0;
	while((ch=getchar())!=EOF)
	{
		if(isupper(ch))
			count1++;
		if(islower(ch))
			count2++;
	}
	printf("%d %d",count1,count2);
}

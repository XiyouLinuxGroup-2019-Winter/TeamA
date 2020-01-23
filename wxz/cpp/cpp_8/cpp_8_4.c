#include <stdio.h>
#include <ctype.h>
int main()
{
	char ch;
	int count=0;
	int temp=0;
	int count1=0;
	while((ch=getchar())!=EOF)
	{
			if(isalpha(ch))
			{
				temp=1;
				count++;
			}
			else if(temp==1)
			{
				count1++;
				temp=0;
			}
	}
	printf("%f\n",(float)count/(float)count1);
}

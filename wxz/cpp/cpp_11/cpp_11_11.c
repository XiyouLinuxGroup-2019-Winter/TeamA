#include <stdio.h>
#include <ctype.h>
int main()
{
	char ch;
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0;
	int i;
	while((ch=getchar())!=EOF)
	{
		if(isalpha(ch))
		{
			if(i==0)
			{
				cnt1++;
				i=1;
			}
		}
		else
		{
			if(i=0)
			{
				if(isupper(ch))
					cnt2++;
					if(islower(ch))
						cnt3++;
						if(ispunct(ch))
							cnt4++;
							if(isdigit(ch))
								cnt5++;
			}
		}
	}
	printf("%d  %d %d %d  %d",cnt1,cnt2,cnt3,cnt4,cnt5);
}

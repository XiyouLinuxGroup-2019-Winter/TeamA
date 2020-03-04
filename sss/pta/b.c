#include <stdio.h>
int main()
{
        int i,j,count[10]={0};
        char s[1001];
        gets(s);
        for(i=0;i<10;i++)
	{
		for(j=0;s[j];j++)
                if(s[j]==i+'0')
                  count[i]++;
	}
        for(i=0;i<10;i++)
        {
              if(count[i]==0)
                 continue;
              else
                 printf("%d:%d\n",i,count[i]);
        }
        return 0;
}

#include <stdio.h>
#include <string.h>
char a[1000], b[1000], c[10000],d[10000],sum[1000];
int main()
{
	int aLen = strlen(a);
	int bLen = strlen(b);
	int i = 0;
	int j=0;
	scanf("%s",a);
	scanf("%s",b);
	for(i=aLen-1;i>=0;i--)
	c[j++]=a[i];
	c[j]='\0';
	j=0;
	for(i=bLen-1;i>=0;i--)
	d[j++]=b[i];
	d[j]='\0';
	
	int maxLen = 0, minLen = 0;
	char flag;
	if (aLen > bLen)
	{
		maxLen = aLen;
		minLen = bLen;
		flag = 'B';
	}
	else
	{
		maxLen = bLen;
		minLen = aLen;
		flag = 'A';
	}


	for (i = maxLen - 1; i >= 0; i--)
	{
		if (flag == 'A')
		{
			if (i >= minLen)
				a[i] = '0';
			else
				break;
		}
		else
		{
			if (i >= minLen)
				b[i] = '0';
			else
				break;
		}
	}


	for (i = maxLen - 1; i >= 0; i--)
	{
		if ((a[i] - '0') + (b[i] - '0') >= 10)
		{
			sum[i + 1]+='1';
			sum[i] = (((a[i] - '0') + (b[i] - '0')) % 10) + '0';
		}
		else
			sum[i] = ((a[i] - '0') + (b[i] - '0')) + '0';
	}
	
	for(i=maxLen-1;i>=0;i--)
	printf("%s",sum[i]);


	return 0;
}


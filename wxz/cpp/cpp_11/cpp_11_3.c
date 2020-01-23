#include <stdio.h>
#include <ctype.h>
void my_string(char* p);
int main()
{
	char a[1000];
	scanf("%s",a);
	//fgets(a,1000,stdin);
	my_string(a);
	//fputs(a,stdout);
	printf("%s\n",a);
}
void my_string(char* p)
{
	int i,j;
	for(i=0;isspace(p[i]);i++)
		continue;
		for(j=i;!isspace(p[j]);j++)
			continue;
			p[j]='\0';
			for(;p[i]!='\0';p++)
				*p=p[i];
			*p='\0';
}

#include <stdio.h>
int main()
{
	char asd[255];
	int i,n;
	n=0;
	while((asd[n]=getchar())!='\n')
		n++;
	for(i=n;i>=0;i--)
		printf("%c",asd[i]);
}


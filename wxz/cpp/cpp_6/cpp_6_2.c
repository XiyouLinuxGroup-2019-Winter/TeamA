#include <stdio.h>
int main()
{
	const int ROWS=5;
	const int CHARS=5;
	int i,j;
	char ch='$';
	for(i=0;i<ROWS;i++)
	{
		for(j=CHARS-i;j<=5;j++)
		printf("%c",ch);
		printf("\n");
	}
}

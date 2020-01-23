#include <stdio.h>
int main()
{
	char name[10];
	scanf("%s",name);
	float height;
	scanf("%f",&height);
	printf("%s,you are %.3f feet tall\n",name,height);
}

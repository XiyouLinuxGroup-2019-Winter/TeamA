#include <stdio.h>
int main()
{
	int num[3][3]={1,2,3,4,5,6,7,8,9};
	printf("%d\n",num[1][-2]);
        printf("%d\n",(-1)[num][5]);
	printf("%d\n",-1[num][5]);
	return 0;
}

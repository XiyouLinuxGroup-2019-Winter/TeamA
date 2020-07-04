/*************************************************************************
	> File Name: 2019_13.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月17日 星期一 14时06分32秒
 ************************************************************************/

#include<stdio.h>
int check_sys()
{
	union
	{
		int i;
		char c;
	}un;
	un.i=1;
	return un.c;
}
int main()
{
 	int ret = check_sys();
 	if(ret == 1)
 	{
 		printf("小端\n");
 	}
 else
 	{
 		printf("大端\n");
 	}
}

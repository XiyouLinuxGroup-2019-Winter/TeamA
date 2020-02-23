/*************************************************************************
	> File Name: 2018_12.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月16日 星期日 23时45分30秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
	FILE *fp = fopen("Linux.txt", "wb");
	long long a = 0x78756e694c;
	fwrite(&a, sizeof(a), 1, fp);
	fclose(fp);
}

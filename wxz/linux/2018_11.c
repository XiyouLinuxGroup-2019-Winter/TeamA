/*************************************************************************
	> File Name: 2018_11.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月16日 星期日 23时50分33秒
 ************************************************************************/

#include<stdio.h>
struct icd {
	int a;
	char b;
	double c;
};
struct cdi {
	char a;
	double b;
	int c;
};
int main(int argc, char *argv[])
{
	printf("%zu %zu\n", sizeof(struct icd), sizeof(struct cdi));
}

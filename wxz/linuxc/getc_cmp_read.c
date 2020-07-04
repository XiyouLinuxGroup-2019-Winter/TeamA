/*************************************************************************
	> File Name: getc_cmp_read.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 19时44分15秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
int main()
{
    FILE* fp,*fp_out;
    int n;

    fp=fopen("mmp_test","r");
    if(fp==NULL)
    {
        perror("fopen error");
        exit(1);
    }

    fp_out=fopen("mmp_test.cp","w");
    if(fp_out==NULL)
    {
        perror("fopen error");
        exit(1);
    }

    while((n=fgetc(fp))!=EOF)
        fputc(n,fp_out);

    fclose(fp);
    fclose(fp_out);
}

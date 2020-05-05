# include <stdio.h>
# include <stdlib.h>
# include <string.h>
 
# define LEN 255 
 
int main(int argc , char * argv[])
{
	char line[LEN] ;
	FILE * fp ;
 
	if (argc != 3)
	{
		fputs("参数错误.\n" , stderr);
		exit(EXIT_FAILURE);
	}
 
	if (!(fp = fopen(argv[2] , "r")))
	{
		fprintf(stderr , "无法打开文件:%s\n" , argv[2]);
		exit(EXIT_FAILURE);
	}
 
	while (fgets(line , LEN , fp))
	{
		if (strstr(line , argv[1]))
			fputs(line , stdout);
	}
 
	if (fclose(fp))
	{
		fputs("文件退出失败.\n" , stderr);
		exit(EXIT_FAILURE);
	}
 
	return 0 ;
}


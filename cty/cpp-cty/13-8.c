# include <stdio.h>
# include <stdlib.h>
 
long filechr(int ch , FILE * fp);
 
int main(int argc , char * argv[])
{
	FILE * fp ;
 
	if (argc < 2)
	{
		fprintf(stderr , "参数错误.\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		printf("请输入你要检查%s存在次数的内容(结束符停止)\n" , argv[1]);
		printf("您输入的内容中%s出现了%ld次.\n", argv[1] , filechr(*argv[1] , stdin));
	}
	else 
	{
		for (int i = 2 ; i < argc ; i++)
		{
			if (!(fp = fopen(argv[i] , "r")))
			{
				fprintf(stderr , "%s文件无法打开.\n" , argv[i]);
				continue ;
			}
			printf("文件%s中%s出现了%ld次.\n" , argv[i] , argv[1] , filechr(*argv[1] , fp));
			if (fclose(fp))
			{
				fprintf(stderr , "%s文件退出失败.\n" , argv[i]);
				exit(EXIT_FAILURE);
			}
		}
	}
 
	return 0 ;
}
 
long filechr(int ch , FILE * fp)
{
	long ret_val = 0 ;
	char tmp ;
 
	while ((tmp = getc(fp)) != EOF)
	{
		if (ch == tmp)
			ret_val++ ;
	}
	return ret_val; 
}


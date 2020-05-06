# include <stdio.h>
# include <stdlib.h>
 
int main(int argc , char * argv[])
{
	FILE * fp ;
	char ch ;
 
	while (--argc > 0)
	{
		if (!(fp = fopen(*++argv , "r")))
		{
			fprintf(stderr , "打开%s文件失败.\n" , *argv);
			continue ;
		}
		
		while ((ch = getc(fp)) != EOF)	
			putc(ch ,stdout);
 
		if (fclose(fp))
		{
			fprintf(stderr , "退出%s文件失败.\n" , *argv);
			exit(EXIT_FAILURE);
		}
	}
 
	return 0 ;
}


# include <stdio.h>
# include <stdlib.h>
 
# define LEN 100
 
int main(void)
{
	long num ;
	char fname[LEN] ;
	char ch ;
	FILE * fp ;
 
	puts("Please enter file name:");
	scanf("%s" , fname);
 
	if (!(fp = fopen(fname , "r")))
	{
		fprintf(stderr , "Can't open file %s.\n" , fname);
		exit(EXIT_FAILURE);
	}
 
	puts("Please enter a number:(< 0 to quit)");
	while (scanf("%ld" , &num) && num >= 0)
	{
		while (getchar() != '\n') ; 
 
		fseek(fp , num , SEEK_SET); //定位到指定位置
 
		while ((ch = getc(fp)) != '\n') //从指定位置输出字符直到遇到\n
			putc(ch , stdout) ;
		putchar('\n');//换行
 
		puts("Please enter a number:(< 0 to quit)");
	}
	
	puts("Done !");
 
	return 0 ;
}


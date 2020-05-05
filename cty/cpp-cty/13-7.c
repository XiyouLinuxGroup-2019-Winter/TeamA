# include <stdio.h>
# include <stdlib.h>
 
# define LEN 100
 
void function_a(FILE * f1 , FILE * f2);
void function_b(FILE * f1 , FILE * f2);
 
int main(int argc , char * argv[])
{
	FILE * fp1 , * fp2 ;
 
	if (argc != 3)
	{
		fprintf(stderr , "参数错误");
		exit(EXIT_FAILURE);
	}
 
	if (!(fp1 = fopen(argv[1] , "r")))
	{
		fprintf(stderr , "%s 文件无法打开.\n" , argv[1]);
		exit(EXIT_FAILURE);
	}
 
	if (!(fp2 = fopen(argv[2] , "r")))
	{
		fprintf(stderr , "%s 文件无法打开.\n" , argv[2]);
		exit(EXIT_FAILURE);
	}
 
	puts("a小题执行结果:");
	function_a(fp1 , fp2) ;
 
	
		rewind(fp1);
			rewind(fp2);
			 
			 	puts("b小题执行结果:");
		 		function_b(fp1 , fp2) ;
			 		 
			 		 	if (fclose(fp1) || fclose(fp2))
			 		 			fprintf(stderr , "文件关闭失败.\n");
			 		 				
			 		 					return 0 ;		 		 					}
	
			 		 					 void function_a(FILE * f1 , FILE * f2)
			 		 					 {
			 		 					 	char ch1 , ch2 ;
			 		 					 	 
			 		 					 	 	do
			 		 					 	 		{
			 		 					 	 				while ((ch1 = getc(f1)) != EOF && ch1 != '\n')
			 		 					 	 						{
			 		 					 	 									putc(ch1 ,stdout) ;
			 		 					 	 												putchar('\n');
			 		 					 	 														}
			 		 					 	 														 
			 		 					 	 														 		while ((ch2 = getc(f2)) != EOF && ch2 != '\n')
			 		 					 	 														 				{
			 		 					 	 														 							putc(ch2 ,stdout) ;
			 		 					 	 														 										putchar('\n');
			 		 					 	 														 												}
			 		 					 	 														 												 
			 		 					 	 														 												 	}while (ch1 != EOF && ch2 != EOF) ;
			 		 					 	 														 												 	}
			 		 					 	 														 												 	 
			 		 					 	 														 												 	 void function_b(FILE * f1 , FILE * f2)
			 		 					 	 														 												 	 {
			 		 					 	 														 												 	 	char ch1 , ch2 ;
			 		 					 	 														 												 	 	 
			 		 					 	 														 												 	 	 	do
			 		 					 	 														 												 	 	 		{
			 		 					 	 														 												 	 	 				while ((ch1 = getc(f1)) != EOF && ch1 != '\n')
			 		 					 	 														 												 	 	 						{
			 		 					 	 														 												 	 	 									putc(ch1 ,stdout) ;
			 		 					 	 														 												 	 	 											}
			 		 					 	 														 												 	 	 											 
			 		 					 	 														 												 	 	 											 		while ((ch2 = getc(f2)) != EOF && ch2 != '\n')
			 		 					 	 														 												 	 	 											 				{
			 		 					 	 														 												 	 	 											 							putc(ch2 ,stdout) ;
			 		 					 	 														 												 	 	 											 									}
			 		 					 	 														 												 	 	 											 											putchar('\n');
			 		 					 	 														 												 	 	 											 											 
			 		 					 	 														 												 	 	 											 											 	}while (ch1 != EOF && ch2 != EOF) ;
	}		 		 					 	 														 												 	 	 											 											 

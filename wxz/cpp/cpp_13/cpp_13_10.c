#include <stdio.h>
#include <stdlib.h>
int main()
{
	 FILE* fp;
	 char f[100];
	 char ch;
	 int num;
	 scanf("%s",f);

	 if((fp=fopen(f,"r"))==NULL)
	 {
		 fprintf(stderr,"Can't open the file\n");
		 exit(1);
	 }
	 while(scanf("%d",&num)==1 && num!=0)
	 {
		 while((getchar())!='\n')
		 fseek(fp,num,SEEK_SET);
		 while((ch=getc(fp))!='\n')
		 putc(ch,stdout);
		 putchar('\n');
	 }
	 fclose(fp);
	 fp=NULL;
}

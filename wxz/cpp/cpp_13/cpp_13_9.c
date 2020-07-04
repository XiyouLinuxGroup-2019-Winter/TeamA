#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE* fp;
	int num;
	char words[100];
	if((fp=fopen("words","a+"))==NULL)
	{
		fprintf(stdout,"Can't open the file\n");
		exit(1);
	}
	puts("Enter words to add to the file:press the Enter\n");
	puts("key at the beginning of a line to terminate.\n");
	while(fscanf(stdin,"%s",words)==1 && words[0]!='#')
		fprintf(fp,"%s %d",words,++num);
	puts("File contents:\n");
	rewind(fp);
	while(fscanf(fp,"%s %d",words,&num)==2)
		fprintf(stdout,"%s %d",words,num);
	fclose(fp);
	fp=NULL;
}

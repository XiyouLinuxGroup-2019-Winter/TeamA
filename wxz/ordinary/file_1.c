#include <stdio.h>
#include <string.h>
#include <errno.h>
/*
int main()
{
	int a=10000;
	FILE* pf=fopen("text.txt","wb");
	fwrite(&a,4,1,pf);//二进制的形式写到文件中
	fclose(pf);
	pf=NULL;
}*/
/*int main()
{
	int ch=getchar();
	printf("%c\n",ch);
	ch=getchar();
	printf("%c\n",ch);
	ch=getchar();
	printf("%c\n",ch);
	ch=getchar();
	printf("%c",ch);
	//ch=getchar();
	//printf("%c",ch);
}*/

/*int main()
{
	while(1)
	{
		printf("hehe");
		sleep(1);
	}
}*/
/*
int main()
{
	FILE* pf=fopen("text.txt","w");
	if(pf==NULL)
		printf("%s\n",strerror(errno));
	//写文件
	fputc('b',pf);
	fputc('i',pf);
	fputc('t',pf);
	fputc('w',stdout);
	fputc('c',stdin);
	//关文件
	fclose(pf);
	pf=NULL;
}*/


/*int main()
{
	int ch;
	char buf[20]={0};
	FILE* pf=fopen("text.txt","r");
	if(pf==NULL)
	{
		return 0;
	}
	//读文件
	fgets(buf,20,pf);
	printf("%s\n",buf);
	//ch=fgetc(pf);
	//putchar(ch);
	//ch=fgetc(pf);
	//putchar(ch);
	//ch=fgetc(pf);
	//putchar(ch);
	
	fclose(pf);
	pf=NULL;
}*/

/*int main()
{
	char buf[20];
	FILE* pf=fopen("text.txt","w");
	if(pf==NULL)
		return 0;
	//写文件
	fputs("hello bit",pf);

	fclose(pf);
	pf=NULL;
}*/


struct Stu
{
	char name[20];
	int age;
	float score;
};

/*int main()
{
	struct Stu s={"张三",20,55.5f};
	char buf[20];
	FILE* pf=fopen("text","w");
	if(pf==NULL)
		return 0;
	//写文件
	fprintf(pf,"%s %d %f",s.name,s.age,s.score);
	
	fclose(pf);
	pf=NULL;
}*/

/*int main()
{
	struct Stu s={0};
	FILE* pf=fopen("text.txt","r");
	if(pf==NULL)
		return 0;
	fscanf(pf,"%s %d %f",s.name,&(s.age),&(s.score));
	printf("%s %d %f\n",s.name,s.age,s.score);

	fclose(pf);
	pf=NULL;
}*/


/*int main()
{
	struct Stu s={"张三",20,55.5f};
	FILE* pf=fopen("text.txt","wb");
	if(pf==NULL)
		return 0;
	//二进制写文件
	fwrite(&s,sizeof(s),1,pf);
	
	fclose(pf);
	pf=NULL;
}*/


int main()
{
	struct Stu s={"张三",2,55.5f};
	FILE* pf=fopen("text.txt","rb");
	if(pf==NULL)
		return 0;
	//二进制读文件
	fread(&s,sizeof(struct Stu),1,pf);
	printf("%s %d %f\n",s.name,s.age,s.score);

	fclose(pf);
	pf=NULL;
}





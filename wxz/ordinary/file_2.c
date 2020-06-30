#include <stdio.h>
#include <string.h>
/*struct Stu
{
	char name[20];
	int age;
	float score;
};

//序列化和反序列化
int main()
{
	char buf[50]={0};
	struct Stu tmp={0};
	struct Stu s={"张三",20,55.5f};
	//把结构体转化为字符串
	sprintf(buf,"%s %d %f",s.name,s.age,s.score);
	printf("%s\n",buf);
	
	//把字符串转化为结构体
	sscanf(buf,"%s %d %f",tmp.name,&(tmp.age),&(tmp.score));
	printf("%s %d %f\n",tmp.name,tmp.age,tmp.score);
}*/

/*int main()
{
	FILE* pf=fopen("test.txt","r");
	int ch=0;
	if(pf==NULL)
		return 0;
	//读文件
	ch=fgetc(pf);
	printf("%c\n",ch);
	//定位文件指针
	fseek(pf,3,SEEK_SET);
	//a b c d e f
	ch=fgetc(pf);
	printf("%c\n",ch);

	printf("%d\n",ftell(pf));

	fclose(pf);
	pf=NULL;
}*/

int main()
{
	int ch=0;
	FILE* pfWrite=NULL;
	FILE* pfRead=fopen("test.txt","r");
	if(pfRead==NULL)
		return 0;
	pfWrite=fopen("test2.txt","w");
	if(pfWrite==NULL)
	{
		fclose(pfRead);
		return 0;
	}
	//拷贝
	while((ch=fgetc(pfRead))!=EOF)
	{
		fputc(ch,pfWrite);
	}
	printf("%d\n",feof(pfRead));
	fclose(pfRead);
	fclose(pfWrite);
	pfWrite=NULL;
	pfRead=NULL;
}



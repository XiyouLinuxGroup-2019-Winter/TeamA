#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv,char **environ)//要打印环境变量表时，environ所在的位置
{
	int i=0;
	for(i=0;i<argc;i++)
	{
		printf("%s ",argv[i]);
	}
	printf("\n------------------------\n");

	//for(i=0;NULL!=environ[i];i++)
	//{
	//	printf("%s ",environ[i]);
        //	}
       printf("1111111111111");
	printf("\n-----------------------------\n");
}


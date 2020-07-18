#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 300
int main()
{

    char name_t[MAX_CHAR];
   printf("请输入要添加好友的账号:");
    scanf("%s",name_t);
    while(getchar()!='\n')
		  continue;
    char str[MAX_CHAR];
    sprintf(str,"%s",name_t);
    //if(Send_message(6,name_t,"")==1);
      //  printf("好友请求发送成功");
    //return;
}
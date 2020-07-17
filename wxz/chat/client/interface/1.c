#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct group
{
    char name[30];
    int id;
    int num;
    int owner;

}group;

int main()
{
    char a[30];
      //char name_t[30];
    char str[30];
    group group;
    memset(str,0,sizeof(str));
    printf("请输入群名:");
    scanf("%s",group.name);
    //group.ower=entenum;
    //group.flag=17;
    memcpy(str,&group,sizeof(group));
    printf("%s",str);
}
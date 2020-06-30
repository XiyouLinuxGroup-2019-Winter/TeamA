#include <stdio.h>
#include <unistd.h>
int main()
{
    char *ch;
    ch=getpass("请输入密码:");
    printf("%s",ch);
}
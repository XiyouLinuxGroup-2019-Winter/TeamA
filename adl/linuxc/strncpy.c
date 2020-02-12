#include<stdio.h>
#include<string.h>
int main()
{
    char *s="saddd";
    char s2[1000];
    strncpy(s2,s,4);
    // for (int i = 0; i < 100; i++)
    // {
    //     printf("%c",s2[i]);
    // }
    char arglist[2][256]={"asd","asd"};
    char*arg[2];
    for (int i = 0; i < 2; i++)
    {
        arg[i]=arglist[i];
    }
    printf("%s",arg[1]);
}
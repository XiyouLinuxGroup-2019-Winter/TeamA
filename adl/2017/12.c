#include<stdio.h>
#include<string.h>
int main()
{
    // while (1)
    // {
    //     fprintf(stdout,"Group");
    //     fprintf(stderr,"xiyoulinux");
    //     getchar();
    // }
    char str[512];
    for (int i = 0; i < 512; i++)
    {
        printf("%c",( char)(-i-1));
        str[i]=-1-i;
    }
    printf("%lu",strlen(str));
    printf("%d",'!');
int a=-255;

}
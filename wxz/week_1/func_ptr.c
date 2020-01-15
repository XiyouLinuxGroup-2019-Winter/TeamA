/*************************************************************************
	> File Name: func_ptr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 16时07分49秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <ctype.h>

char showmenu();
void eatline();//读至行末
void show(void(*fp)(char*),char* str);
void ToUpper(char*);//把字符串转成大写
void ToLower(char*);//把字符串转成小写
void Transpose(char*);
void Dummy(char*);
int main()
{
    char line[81];
    char copy[81];
    char choice;
    void (*pfun)(char*);//指向一个函数
                        //一个char*参数，并且没有返回值
                        //
    puts("Enter a string (empty line to quit:)");
    while((fgets(line,81,stdin))!=NULL && line[0]!='\0');
    {
        while((choice=showmenu())!='\n')
        {
            switch(choice)
            {
                case 'u':pfun=ToUpper;break;
                case 'l':pfun=ToLower;break;
                case 't':pfun=Transpose;break;
                case 'o':pfun=Dummy;break;
            }
            strcpy(copy,line);
            show(pfun,copy);
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");
}


char showmenu()
{
    char ch;
    puts("Enter menu chocie:\n");
    puts("u)uppercase   1)lowercase\n");
    puts("t)Transposed case  o)original case\n");
    puts("n)next string\n");
    ch=getchar();
    ch=tolower(ch);
    eatline();
    while(strchr("ulton",ch)==NULL)
    {
        puts("Please enter a u l t o, or ,n:\n");
        ch=tolower(getchar());
        eatline();
    }
    return ch;
}

void eatline()
{
    while(getchar()!='\n')
    continue;
}

void ToUpper(char* str)
{
    while(*str)
    {
        *str=toupper(*str);
        str++;
    }
}

void ToLower(char* str)
{
    while(*str)
    {
        *str=tolower(*str);
        str++;
    }
}

void Transpose(char* str)
{
    while(*str)
    {
        if(islower(*str))
            *str=toupper(*str);
        else if(isupper(*str))
            *str=tolower(*str);
        str++;
    }
}

void Dummy(char* str)
{
    //不改变字符串
}


void show(void(*fp)(char*),char* str)
{
    (*fp)(str);
    puts(str);
}




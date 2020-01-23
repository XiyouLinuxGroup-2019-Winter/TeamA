/*************************************************************************
	> File Name: cpp_14_1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月11日 星期六 14时23分13秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
struct modern{
    char name_month[100];
    char abbr_month[3];
    int day;
    int number_day;
};

int main()
{
    struct modern month[12]={
        {"january","jan",31,1},
        {"febyuary","feb",28,2},
        {"march","mar",31,3},
        {"april","apr",30,4},
        {"may","may",31,5},
        {"june","jun",30,6},
        {"july","jul",31,7},
        {"august","aug",31,8},
        {"september","sep",30,9},
        {"october","oct",31,10},
        {"novermber","nov",30,11},
        {"december","dec",31,12}
    };
    char s[10];
    int i;

    while(fgets(s,10,stdin)!=NULL && s[0]!='\0')
    {
        int flag=0;
        for(i=0;i<12;i++)
        {
            if(strcmp(month[i].name_month,s)==0)
            {
                flag=1;
            }
        }
        if(flag==1)
        fputs(s,stdout);
        else if(flag==0)
        puts("程序错误\n");
    }
   
}

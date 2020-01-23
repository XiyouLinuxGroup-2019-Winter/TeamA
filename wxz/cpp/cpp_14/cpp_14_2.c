/*************************************************************************
	> File Name: cpp_14_2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月11日 星期六 16时02分03秒
 ************************************************************************/

#include<stdio.h>

int input(int year,int day,int month);
struct modern{
    char name[10];
    char abbrev[3];
    int days;
    int month;
};
struct modern months[13] = {
    {"zero","wu",0,0},
	{"january","jan",31,1},
	{"february","feb",28,2},
    {"march","mar",31,3},
	{"april","apr",30,4},
	{"may","may",31,5},
	{"june","jun",30,6},
	{"july","jul", 31,7},
	{"august","aug",31,8},
	{"september","sep",30,9},
	{"october","oct",31,10},
	{"november","nov",30,11},
	{"december","dec",31,12}
    };
int main()
{
    int year,mon,day;
    int sum=0;
    while(scanf("%d %d %d",&year,&mon,&day)==3)
    {
            sum=input(year,day,mon);
            printf("%d\n",sum);
    }
}

int input(int year,int day,int month)
{  
    int sum=0;
    for(int i=1;i<month;i++)
    {
        if((year%4==0 && year%100!=0) || year%400==0)
            months[2].days=29;
        else
            months[2].days=28;

        sum+=months[i].days;
    }
    return (sum+day);
}

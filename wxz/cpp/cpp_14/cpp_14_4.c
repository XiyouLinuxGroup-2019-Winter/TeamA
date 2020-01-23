/*************************************************************************
	> File Name: cpp_14_4.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月11日 星期六 19时20分41秒
 ************************************************************************/

#include<stdio.h>
void show_a(struct info ff);
void show_b(struct info* ff,int n);
struct fullname{
    char first[20];
    char middle[20];
    char last[20];
};

struct info{
    int num;
    struct fullname name;
};

struct info ff[5]={
        {302039823,{"dribble","ma","flossie"}},
        {304545435,{"sedwfee","sw","wedfefr"}},
        {345446454,{"swwedwe","sx","frterrtr"}},
        {321234556,{"dfddgtr","fr","rgtyytyt"}},
        {345467676,{"rtgyttt","tr","rtgtrtgt"}}
    };
int main()
{
    for(int i=0;i<5;i++)
    show_a(ff[i]);
    
    show_b(ff,5);
}
void show_a(struct info ff)
{
    printf("%s,%s-%d\n",ff.name.first,ff.name.last,ff.num);
}
void show_b(struct info *ff,int n)
{
    for(int i=0;i<n;i++)
    printf("%s.%s %c.
           -%d\n",ff[i].name.first,ff[i].name.last,ff[i].name.middle[0],ff[i].num);
}


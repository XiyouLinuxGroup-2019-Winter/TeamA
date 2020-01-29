#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct a
{
    char*name;
    int num;
}A,*PA;
void fun(PA*a)
{
    *a=(A*)malloc(sizeof(A));
//    (*a)->name=malloc(sizeof("XIyoulinuxgroup"));
//     strcpy((*a)->name,"XIyoulinuxgroup");
    (*a)->name="XIyoulinuxgroup";
    (*a)->num=2018;
}
int main()
{
    PA a;
    fun(&a);
    printf("%s%d\n",a->name,a->num);
    return 0;
}
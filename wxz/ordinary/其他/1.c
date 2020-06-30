#include <stdio.h>
int main()
{
    struct Stu{
        char a[6];
        char name[10];
        double source;
    }stu[11];
    int n;
    scanf("%d",&n);
    int i=0;
    double sum;
    for(i=0;i<n;i++)
    {
        scanf("%s %s %lf",stu[i].a,stu[i].name,stu[i].source);
        sum+=stu[i].source;
    }
    double aver=(sum)/n;
    printf("%.2lf\n",aver);
    for(i=0;i<n;i++)
    {
        if(stu[i].source<aver)
            printf("%s %s\n",stu[i].name,stu[i].a);
    }
}

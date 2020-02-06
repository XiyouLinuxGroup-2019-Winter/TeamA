#include <string.h>
#include <stdio.h>
typedef struct list
{
    int cur;
    int next;
    int pre;
} List;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    List list[n];
    for (int i = 0; i < n; i++)
    {
        
            list[i].cur = i + 1;
        list[i].next = (i + 1) % n;
        if(i==0)list[i].pre =n-1;//
        else list[i].pre=i-1;
    }
    int lead = 0;
    int q=k;
    while (k--)
    {
        int a;
        scanf("%d", &a);
        a=a%(n+k-q+1);
        while (a--)
            lead = list[lead].next;
        list[list[lead].pre].next=list[lead].next;
        list[list[lead].next].pre=list[lead].pre;
        printf("%d ",list[lead].cur);
        lead=list[lead].next;
    }
}
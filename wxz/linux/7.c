/*************************************************************************
	> File Name: 7.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月18日 星期二 17时30分02秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
/*struct node
{
 	char a;
 	short b;
 	int c;
};
int main()
{
	struct node s;
	memset(&s,0,sizeof(s));
	s.a=3;
	s.b=5;
	s.c=7;
	struct node *pt=&s;
	printf("%d\n",*(int *)pt);
	printf("%lld\n",*(long long*)pt);
	return 0;
}*/
#include<stdio.h>


/*struct node1
{
    int  a;
    int  b;
    int  c;
};
struct node2
{
    char  a;
    char  b;
    short c;
    int   d;
};
int main()
{
    struct node1 s1 = {3,5,6};
    struct node2 s2 = {3,5,6,99};
    struct node *p1 =&s1;
    struct node *p2 =&s2;
    printf("%d\n",*(int *)p1);
    printf("%d\n",*(int *)p2);
}*/
typedef struct node{
    
}s;
int main()
{
    printf("%d",sizeof(s));
}



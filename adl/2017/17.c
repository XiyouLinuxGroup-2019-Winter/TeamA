#include<stdio.h>
#include<string.h>
struct node
{
char a;//3   2      0000000000000011
short b;//5   2     0000000000000101
int c;//7           4       00000000000000000000000000000111
};
int main(int argc, char *argv[])
{
struct node s;
memset(&s, 0, sizeof(s));
s.a = 3;
s.b = 5;
s.c = 7;
struct node *pt = &s;
printf("%x\n", *(int*)pt);
printf("%llx\n", *(long long *)pt);
return 0;
}
//0000001100000000
//0000000000000101
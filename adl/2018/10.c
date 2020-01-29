#include<stdio.h>
#define YEAR 2018
#define LEVELONE(x) "xiyoulinux"#x"\n"
#define LEVELTWO(x) LEVELONE(x)
#define MULTIPLY(x,y) x*y
int main()
{
    int x=MULTIPLY(1+2,3);
    printf("%d\n",x);
    printf(LEVELONE(YEAR));
    printf(LEVELTWO(YEAR));
    
}
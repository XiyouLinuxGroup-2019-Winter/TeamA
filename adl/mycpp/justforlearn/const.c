#include<stdio.h>
const int  a=10;
extern int sad();
int main(){
    printf("%d",a+sad());
    return 0;
}
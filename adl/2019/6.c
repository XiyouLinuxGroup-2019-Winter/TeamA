#include<stdio.h>

int main(int argc, char *argv[]) {
char x = -2, y = 3;
char t = (++x) | (y++);//-1,3--------->ff||11-->ff

//0~127--------------------00000000,01111111,-128~-1------------10000000   11111111
printf("x = %d, y = %d, t = %d\n", x, y, t);
t = (++x) || (y++);//0||4==1
printf("x = %d, y = %d, t = %d\n", x, y, t);
}
#include<stdio.h>
int main(int argc, char* argv[])
{
    char** st;
    for (st = argv + argc -1; st > argv; st--)
        printf("%s ",*st);
    putchar('\n');
 
    return 0;
}

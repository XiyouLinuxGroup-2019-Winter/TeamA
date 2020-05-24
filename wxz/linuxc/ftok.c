#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
int main()
{
    int i;
    for(i=1;i<=5;i++)
    {
        printf("key[%d]=%ul\n",ftok(".",i));
        exit(0);
    }
}
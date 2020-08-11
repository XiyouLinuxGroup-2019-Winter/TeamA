#include <stdio.h>
#include <time.h>
int main()
{
    time_t timep;
    timep=time(&timep);
    printf("%s\n",ctime(&timep));
    //printf("%s\n",time(&timep));

}
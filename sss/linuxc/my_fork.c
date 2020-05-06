#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

      pid_t ret;

      ret=fork();

      printf("%d,ret=%d\n",getpid(),ret);
      while(1);

     
}


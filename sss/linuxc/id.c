#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

      pid_t pid;
      pid_t ppid;
      uid_t uid;
      gid_t gid;
      
      pid=getpid();
      ppid=getppid();
      uid=getuid();
      gid=getgid();


      printf("pid=%d\n",pid);
      printf("ppid=%d\n",ppid);
      printf("uid=%d\n",uid);
      printf("gid=%d\n",gid);

      while(1);
}


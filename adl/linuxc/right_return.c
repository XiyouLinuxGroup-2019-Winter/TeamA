#include<stdio.h>
#ifndef    __USE_POSIX
#define __USE_POSIX
#endif
#include<setjmp.h>
#include<signal.h>
#include<unistd.h>
#define ENV_UNSAVE 0

#define ENV_SAVED 1
int flag_saveenv    =ENV_UNSAVE;
jmp_buf env;
void handler_sigrtmin15(int signo)
{
   if(flag_saveenv==ENV_UNSAVE){
       return;
   }
    printf("recv SIGMIN+15\n");
    sleep(10);
    printf("in handler_sigrtmin15,after sleep\n");
    siglongjmp(env,1);
}
int main()
{

    signal(SIGRTMIN+15,handler_sigrtmin15);
    sleep(30);/*如果这个时候发信号则recv SIGMIN+15
in handler_sigrtmin15,after sleep
段错误 (核心已转储)*/
    switch (sigsetjmp(env,1))//它文中的意思是先signal
    {
    case 0:
       printf("return 0\n");
       flag_saveenv=ENV_SAVED;
        break;
    case 1:
        printf("return from SIGRTMIN+15\n");
        break;
    default:
        printf("return else\n");
        break;
    }
    signal(SIGRTMIN+15,handler_sigrtmin15);
    while(1)
    ;
}
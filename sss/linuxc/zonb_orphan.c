#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

	pid_t ret=0;
	ret=fork();
	/*if(ret>0)
	{
                     while(1);
	}

	else if(ret==0)
	{
		
	}
	return 0;*/
	if(ret>0)
	{
	}
	else if(ret==0)
	{
		while(1);
	}
	return 0;

         
}


#include <stdio.h>
#include <assert.h>
char *my_strncpy(char* s1,const char* s2,size_t n);
int main()
{
	char *p="abcd";
	char q[5];
	char* ret=my_strncpy(q,p,3);
	printf("%s\n",ret);
}
char* my_strncpy(char* s1,const char* s2,size_t n)
{
	assert(s1!=NULL);
	assert(s2!=NULL);
	char* ret=s1;
	while(n)
	{
		*s1++=*s2++;
		n--;
	}		
		*s1='\0';
		return ret;
}


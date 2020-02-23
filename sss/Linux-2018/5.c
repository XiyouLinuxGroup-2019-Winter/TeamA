#include <stdio.h>
int main()
{
	char y[]="xiyoulinuxgroup",x[]="2018";
	char *const p1=y;
	const char *p2=y;
	p1=x;
	p2=x;
	p1='x';
	p2='x';
}


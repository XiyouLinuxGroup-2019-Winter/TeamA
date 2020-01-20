#include <stdio.h>
void br(void);
void ic(void);
int main()
{
     printf("Brazil, Russia, India, China\n");
     ic();
     br();
}
void br(void)
{
     printf("Brazil, Russia\n");
}
void ic()
{
	printf("India, China\n");
}



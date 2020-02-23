#include <stdio.h>
int main(int argc, char *argv[])
{
int t = 4;
printf("%lu\n", sizeof(t--));
printf("%lu\n", sizeof("ab c\nt\012\xa1*2"));
return 0;
}


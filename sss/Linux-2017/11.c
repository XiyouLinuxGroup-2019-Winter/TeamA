#include <stdio.h>
int main(int argc, char *argv[])
{
int nums[5] = {2, 4, 6, 8, 10};
int *ptr = (int *)(&nums+1);
printf("%d, %d\n", *(nums+1), *(ptr-1));
return 0;
}


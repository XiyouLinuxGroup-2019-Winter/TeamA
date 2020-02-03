#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char ch;
    unsigned int u_count = 0;
    unsigned int l_count = 0;
 
    printf("Please enter some text.(end with EOF)\n");
    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            u_count++;
        else if (islower(ch))
            l_count++;
    }
    printf("Upper case letter: %u\n"
        "Lower case letter: %u\n", u_count, l_count);
 
    return 0;
}

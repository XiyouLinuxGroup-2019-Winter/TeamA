#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char ch;
    unsigned int l_count = 0;
    unsigned int w_count = 0;
    _Bool inword = 0;
 
    printf("Please enter some text.(end with EOF).\n");
    while ((ch = getchar()) != EOF)
    {
        if (!isspace(ch) && !ispunct(ch) && !inword)
        {
            w_count++;
            inword = 1;
        }
        else if (!isspace(ch) && !ispunct(ch) && inword)
            l_count++;
        else if(isspace(ch) || ispunct(ch) && inword)
            inword = 0;
    }
    printf("Average number of letter per word: %.2f\n",
        (float)l_count / w_count);
 
    return 0;
}

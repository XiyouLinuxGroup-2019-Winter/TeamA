#include<stdio.h>
int main(void)
{
    char ch;
    int guess = 50;
    int max = 100;
    int min = 0;
 
    printf("Pick an integer from 1 to 100. "
        "I will try to guess it.\n"
        "Respond with a y if my guess is right.\n"
        "Respond with a b if it is too big "
        "and a s if it is too small.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((ch = getchar()) != 'y')
    {
        if (ch == 'b')
        {
            max = guess;
            guess = (guess + min) / 2;
            printf("Well, then, is it %d\n", guess);
        }
        else if (ch == 's')
        {
            min = guess;
            guess = (guess + max) / 2;
            printf("Well, then, is it %d\n", guess);
        }
        else
            printf("Sorry, I can undersanded y, b, s.\n");
        while (getchar() != '\n')
            continue;
    }
    printf("I know i can do it!\n");
 
    return 0;
}

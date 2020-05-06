#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int roll_n_dice(int dice,int sides);
 
int main(void)
{
    int sets;
    int dice, sides;
    int status;
    int roll;
    int n;
    _Bool re_input = 0;
 
    srand((unsigned int)time(0));
    printf("Enter the number of sets; enter q to stop: ");
    while (scanf_s("%d", &sets))
    {
        printf("How many sides and how many dice? ");
        while ((status = scanf_s("%d %d", &sides, &dice)) != 2 ||
 #define MAX 10
#define TIMES 1000           sides < 2 || dice < 1)
        {
            if (status == EOF)
                break;
            else if (status != 2)
            {
                printf("Please enter integer: ");
                while (getchar() != '\n')
                    continue;
            }
            else
            {
                printf("Requires at least one dice and two sides.\n");
                printf("Re-input: ");
                continue;
            }
        }
 
        printf("Here are %d sets of %d %d-sides throws.\n",
            sets, dice, sides);
        for (n = 0; n < sets; n++)
        {
            roll = roll_n_dice(dice, sides);
            if (roll < 0)
            {
                re_input = 1;
                break;
            }
            printf(" %d", roll);
            if ((n + 1) % 15 == 0)
                putchar('\n');
        }
        printf(“\nHow many sets? Enter q to quit: ");
    }
    printf("\nbye\n");
    return 0;
}

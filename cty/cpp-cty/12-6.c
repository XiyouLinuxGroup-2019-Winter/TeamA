#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define TIMES 1000
#define N_SEED 10
int roll(int max);
void print(int *se, int ar[][MAX], int n);
 
int main(void)
{
    int seed[N_SEED];
    int res[N_SEED][MAX] = { 0 };
    int s_count = 0;
    int r_count;
 
 
    while (s_count < N_SEED)
    {
        printf("Seed %d: ", s_count + 1);
        while (!scanf_s("%d", &seed[s_count]))
        {
            while (getchar() != '\n')
                continue;
            printf("Please enter integer: ");
        }
        srand(seed[s_count]);
        for (r_count = 0; r_count < TIMES; r_count++)
        {
            switch (roll(MAX))
            {
            case 1: res[s_count][0]++; break;
            case 2: res[s_count][1]++; break;
            case 3: res[s_count][2]++; break;
            case 4: res[s_count][3]++; break;
            case 5: res[s_count][4]++; break;
            case 6: res[s_count][5]++; break;
            case 7: res[s_count][6]++; break;
            case 8: res[s_count][7]++; break;
            case 9: res[s_count][8]++; break;
            case 10: res[s_count][9]++; break;
            default: break;
            }
        }
        s_count++;
    }
    printf("\nResult: \n\n");
    print(seed, res, N_SEED);
 
    return 0;
}
 
int roll(int max)
{
    int roll;
 
    roll = rand() % max + 1;
 #define MAX 10
#define TIMES 1000   return roll;
}
 
void print(int *se, int ar[][MAX], int n)
{
    int i, j;
 
    printf(" %-10s","Seed:");
    for (i = 0; i < n; i++)
        printf("%8d", se[i]);
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        printf(" \'%2d\'%-5s ", i + 1,":");
        for (j = 0; j < MAX; j++)
            printf("%8d", ar[i][j]);
        putchar('\n');
    }
}

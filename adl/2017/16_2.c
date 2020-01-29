#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 4096
#define NAMESIZE 20
#define MAXLINE 20
int main(int agrc, char **argv)
{
    int n;
    char name[NAMESIZE];
    char buf[MAXLINE][MAXSIZE] = {0};
    scanf("%s", name);
    FILE *fp = fopen(name, "r");
    puts("第几行？");
    scanf("%d", &n);
    int i = 1;
    while (!feof(fp) && i <= MAXLINE)
    {
        fgets(buf[i - 1], MAXSIZE, fp);

        i++;
    }
    fclose(fp);
    fp = fopen(name, "w");
    for (int j = 1; j < i; j++)
    {
        if (j != n)
            fputs(buf[j - 1], fp);
    }
    fclose(fp);
}
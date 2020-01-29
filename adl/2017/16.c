#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 4096
#define NAMESIZE 20
int main(int agrc, char **argv)
{
    int n;
    char name[NAMESIZE];
    char buf[MAXSIZE];
    scanf("%s", name);
    FILE *fp = fopen(name, "r");
    FILE *fp2 = fopen("copy.txt", "w");
    puts("第几行？");
    scanf("%d", &n);
    int i = 1;
    while (!feof(fp))
    {
        if (i != n)
        {
            fgets(buf, MAXSIZE, fp);
            fputs(buf,fp2);
        }
        else
        {
            fgets(buf,MAXSIZE,fp);
        }
        i++;
    }
    fclose(fp);
    fclose(fp2);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main()
{
    FILE *fp;
    if ((fp = fopen("Linux.txt", "wb")) == NULL)
        printf("wrong\n");

    //long long 8 ->64 //int 4->32//char 1->8
    long long a = 0x78756e694c; //xuniL
                                // //低地址先打印
                                // long long b = 1;
                                // long long *sad = &a;
                                // printf("%c", *(char *)sad);
    if (fwrite(&a, sizeof(a), 1, fp) < 1)
        printf("2wrong\n");

    // fclose(fp);
    // FILE *p = fopen("Linux.txt", "rb");
    //     long long d;
    // rewind(p);
    // fread(&d,sizeof(a),1,p);
    long long d;
    rewind(fp);
    if (fread(&d, sizeof(d), 1, fp) < 1)
    {
        printf("%s", strerror(errno));
        printf("3wrong\n");
    }
    printf("%lld\n%lld\n", d, a);
    printf("%d\n", errno);
    printf("%s", strerror(errno));
    fclose(fp);
}
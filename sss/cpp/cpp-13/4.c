int p13_4(int argc, char **argv)
{
    FILE *fp;
    char buf[256] = { 0 };
    for (int i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            printf("Can't open file %s as read!\n", argv[i]);
        }

        printf("%s:\n", argv[i]);
        while (fgets(buf, 256, fp) != NULL)
        {
            fputs(buf, stdout);
        }

        printf("\n");
    }

    printf("Done!\n");

    return 0;
}


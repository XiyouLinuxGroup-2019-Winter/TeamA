void p13_3(void)
{
    char file_name[256];
    char *tmp_file = "tmp.txt";
    int ch = 0;
    FILE *fp_r;
    FILE *fp_w;

    printf("Enter the file name: ");
    gets_s(file_name, 256);

    if ((fp_r = fopen(file_name, "r+")) == NULL)
    {
        printf("Can't open %s as read mode!\n", file_name);
    }

    if ((fp_w = fopen(tmp_file, "w")) == NULL)
    {
        printf("Can't open %s as write mode!\n", tmp_file);
    }

    while ((ch = fgetc(fp_r)) != EOF)
    {
        ch = toupper(ch);
        fputc(ch, fp_w);

    }

    fclose(fp_r);
    fclose(fp_w);

    if ((fp_r = fopen(tmp_file, "r")) == NULL)
    {
        printf("Can't open %s as read!\n", tmp_file);
    }
    if ((fp_w = fopen(file_name, "w")) == NULL)
    {
        printf("Can't open %s as write!\n", file_name);
    }
    while ((ch = fgetc(fp_r)) != EOF)
    {
        fputc(ch, fp_w);
    }

    fclose(fp_r);
    fclose(fp_w);
    remove(tmp_file);

    printf("Done.\n");

    return;
}


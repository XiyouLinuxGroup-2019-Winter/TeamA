void login()
{
	FILE * fp;
	user old;
	char temp[SIZE];

	show_line("          请开始登录您的账号！");

	if ((fp = fopen("users", "r")) == NULL)
	{
		fprintf(stderr, "读取用户信息失败！\n");
		system("sleep 3s");
		return;
	}
	puts("请输入您的账号：");
	s_gets(temp, SIZE);
	while (!feof(fp))	//判断是否到达文件结尾
	{
		fread(&old, sizeof(user), 1, fp);
		decipher(old.pwd);
		if (!strcmp(temp, old.id))
		{
			puts("请输入您的密码：");
			secret_pwd(temp);
			if (!strcmp(temp, old.pwd))
			{
				show_line("              登录成功！");
				system("sleep 3s");	//休眠，用起来比较带感哈哈哈哈
				internal_menu();
				return;
			}
			else
			{
				puts("密码不匹配！");
				system("sleep 3s");
				return;
			}
		}
	}
	printf("账号%s不存在！\n", temp);
	system("sleep 3s");
	fclose(fp);

	return;
}
char * s_gets(char *st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val != NULL)
	{
		while (st[i] != '\0' && st[i] != '\n')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
void decipher(char *cipher)
{
    int key = -1;
    for (int i = 0; i < strlen(cipher); i++)
    {
        cipher[i] += key;
        key = -key;
    }

	return;
}

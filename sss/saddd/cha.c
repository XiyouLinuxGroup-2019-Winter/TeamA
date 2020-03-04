struct f *find(struct f *head)
{
	printf("请输入要查找的学生的学号！");
	int num;
	scanf("%d",&num);
	head=head->next;
	while(head!=NULL)
	{
		if(head->data==num)
		return head;
	}
	return NULL;
}      


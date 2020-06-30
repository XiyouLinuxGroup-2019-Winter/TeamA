#include <stdio.h>
#include <string.h>
/*int my_strlen(const char* str)
int main()
{
	//字符数组
	char *a[10];
	//字符数组指针
	char *(*p)[10]=&a;
	//函数指针
	int (*pf)(const char*)=my_strlen;
	//函数指针数组
	int (*pfarr[4])(const char*)
	//指向函数指针的数组
	int (*(*ptr)[4])=&pfarr
	
}*/

/*int main()
{
	//数组名在两种的情况下表示整个数组，除此之外都表示首元素地址
	//1.sizeof(数组名)-数组名表示整个数组，sizeof(数组名)计算的是整个数组大小，单位是字节，
	//2.&数组名，数组名表示整个数组，&数组名取出的是整个数组的地址
	//除此之外你遇到的所有的数组名都是首元素的地址
	int a[] = {1,2,3,4};
	int (*pa)[4]=&a;
	//*pa;*&a;
	int num=0;
	int* p=&num;
	//*p //4(指向num,num是4个字节)
	printf("%d\n",sizeof(a));//16计算数组总大小，单位是字节，所以四个元素每个元素是整型
	printf("%d\n",sizeof(a+0));//8(首元素地址加0还是首元素地址)
	printf("%d\n",sizeof(*a));//4(首元素的值，是整型的)
	printf("%d\n",sizeof(a+1));//８
	printf("%d\n",sizeof(a[1]));//４(第二个元素的值，是整型的)
	printf("%d\n",sizeof(&a));//８(取数组的地址)
	printf("%d\n",sizeof(*&a));//16(取数组的地址再解引用访问这个数组,每个元素是四个字节)
	printf("%d\n",sizeof(&a+1));//８(取数组的地址，跳到下一个数组)
	printf("%d\n",sizeof(&a[0]));//８(第一个元素的地址)
	printf("%d\n",sizeof(&a[0]+1));//８(第二个元素地址)
}*/

//字符数组
/*int main()
{
	char arr[]={'a','b','c','d','e','f'};
	printf("%d\n",sizeof(arr));//6
	printf("%d\n",sizeof(arr+0));//8
	printf("%d\n",sizeof(*arr));//1
	printf("%d\n",sizeof(arr[1]));//1
	printf("%d\n",sizeof(&arr));//8
	printf("%d\n",sizeof(&arr+1));//8 
	printf("%d\n",sizeof(&arr[0]+1));//8(第二元素地址)

	printf("%d\n",strlen(arr));//随机值(找'\0'，但是'\0'不可知)
	printf("%d\n",strlen(arr+0));//随机值
	//printf("%d\n",strlen(*arr));//'a'的值是97,97的地址往后读，这个写法是错的
	//printf("%d\n",strlen(arr[1]));//同上
	//printf("%d\n",strlen(&arr));//随机值
	//printf("%d\n",strlen(&arr+1));//数组的地址加1跳到了'f'后面,随机值
	printf("%d\n",strlen(&arr[0]+1));//第二个元素地址往后数,随机值
}*/
/*int main()
{
	char arr[] = "abcdef";
	printf("%d\n",sizeof(arr));//7
	printf("%d\n",sizeof(arr+0));//8
	printf("%d\n",sizeof(*arr));//1
	printf("%d\n",sizeof(arr[1]));//1
	printf("%d\n",sizeof(&arr));//8
	printf("%d\n",sizeof(&arr+1));//8
	printf("%d\n",sizeof(&arr[0]+1));//8

	printf("%d\n",strlen(arr));//6
	printf("%d\n",strlen(arr+0));//6
	//printf("%d\n",strlen(*arr));//错误
	//printf("%d\n",strlen(arr[1]));//错误
	//printf("%d\n",strlen(&arr));//６
	//printf("%d\n",strlen(&arr+1));//随机值
	printf("%d\n",strlen(&arr[0]+1));//5
}*/
/*int main()
{
	char *p = "abcdef";
	/*printf("%d\n",sizeof(p));//8(*p存放指针变量大小)
	printf("%d\n",sizeof(p+1));//８(b的地址大小)
	printf("%d\n",sizeof(*p));//１
	printf("%d\n",sizeof(p[0]));//１
	printf("%d\n",sizeof(&p));//８(不管p是啥，取它地址它就是个地址)
	printf("%d\n",sizeof(&p+1));//８(它是个地址，p有个空间它指向'abcdef'这个字符串的首地址'a'，&p在p这个空间的开头,&p+1指向p这个空间的下一个地方)
	printf("%d\n",sizeof(&p[0]+1));//８

	printf("%d\n",strlen(p));//6
	printf("%d\n",strlen(p+1));//5
	//printf("%d\n",strlen(*p));//错误
	//printf("%d\n",strlen(p[0]));//错误
	//printf("%d\n",strlen(&p));//随机值
	//printf("%d\n",strlen(&p+1));//随机值
	printf("%d\n",strlen(&p[0]+1));//5(第二个元素地址)
}*/

//二维数组
int main()
{
	int a[3][4] = {0};
	printf("%p\n",&a[0][0]);
	printf("%p\n",a+1);//(a+1是第二行的地址，不是第二行第一个元素的地址)
	int* p=NULL;
	int* p=a+1;

	printf("%d\n",sizeof(a));//48
	printf("%d\n",sizeof(a[0][0]));//4
	printf("%d\n",sizeof(a[0]));//16(第一行的大小，4个整型)
	printf("%d\n",sizeof(a[0]+1));//8(首元素的地址+1是第一行第二元素地址)
	printf("%d\n",sizeof(*(a[0]+1)));//4(第一行第二元素的值，是整型)
	printf("%d\n",sizeof(a+1));//8
	printf("%d\n",sizeof(*(a+1)));//16(a+1是第二行的地址解引用，即4个整型大小)
	printf("%d\n",sizeof(&a[0]+1));//８(第一行的地址+1就是第二行的地址)
	printf("%d\n",sizeof(*(&a[0]+1)));//16(第二行的地址解引用，即4个整型大小)
	printf("%d\n",sizeof(*a));//16(第一行的地址解引用)//*a==*(a+0)==a[0]
	printf("%d\n",sizeof(a[3]));//16(sizeof里面的表达式不参与运算，只有a[3]合理的话我们只算它的大小，在编译时刻完成)
}




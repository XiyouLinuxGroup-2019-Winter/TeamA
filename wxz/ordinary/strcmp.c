#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bubble_sort(int arr[],int sz)
{
         int i=0;
         for(i=0;i<sz-1;i++)
         {
                 int j=0;
                  for(j=0;j<sz-1-i;j++)
                 {
                         if(arr[j]>arr[j+1])
                         {
                                 int temp=arr[j];
                                 arr[j]=arr[j+1];
                                 arr[j+1]=temp;
                         }
                 }
 
         }
}
void Print_arr(int arr[],int sz)
{
         int i=0;
         for(i=0;i<sz;i++)
         printf("%d\n",arr[i]);
}
//void qsort
int com_int(const void* e1,const void* e2)
{
	return *(int*)e1 -*(int*)e2;  
}
/*void Test1()
{
        int arr[]={3,1,5,2,4,7,9,6,8,0};
        int sz=sizeof(arr)/sizeof(arr[0]);
        qsort(arr,sz,sizeof(arr[0]),com_int);
        //bubble_sort(arr,sz);
 　　　 Print_arr(arr,sz);
 
}*/
struct Stu
{
        char name[20];
        short age;
};
int cmp_str_by_name(const void*e1,const void*e2)
{
        return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
}
void Test2()
{
        struct Stu arr[]={{"zhangsan",20},{"lisi",50},{"wangwu",15}};
        int sz=sizeof(arr)/sizeof(arr[0]);
        qsort(arr,sz,sizeof(arr[0]),cmp_str_by_name);
	//Print_arr(arr,sz);
}
int main()
{
        /*int a=10;
        float f=3.14f;
        void* pa=&a;
        pa=&f;*/
        //Test1(); 
	Test2();
}

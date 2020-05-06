#include<stdio.h>
#include<stdlib.h>
int* make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void)
{
    int* pa;
        int size;
            int value;
             
                 printf("Enter the number of elements: ");
                     while (scanf_s("%d", &size) == 1 && size > 0)
                         {
                                 printf("Enter the initialization value: ");
                                         if(!scanf_s("%d", &value))
                                         break;
                                                 pa = make_array(size, value);
                                                         if (pa)                                                                 {
                                                                             show_array(pa, size);
                                                                                         free(pa);
                                                                                                 }
                                                                                                         printf("\nEnter the number of elements (<1 to quit): ");
                                                                                                             }
                                                                                                                 printf("Done.\n");
                                                                                                                     return 0;
                                                                                                                     }

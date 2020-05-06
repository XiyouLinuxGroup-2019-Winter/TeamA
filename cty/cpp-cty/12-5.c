
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 10
#define TIMES 100
int roll(int max);
void down(int* pt,int n);
 
int main(void)
{
    int arr[TIMES];
    int* p;
 
    srand((unsigned int)time(0));
    for (p = arr; p < arr + TIMES; p++)
        * p = roll(MAX);
             printf("Random number:\n\n");
                 down(arr, TIMES);
                     for (p = arr; p < arr + TIMES; p++)
                         {
                                 printf("%3d ", *p);
                                         if ((p - arr + 1) % 10 == 0)
                                                     putchar('\n');
                                                         }
                                                          
                                                              return 0;
                                                              }
                                                               
                                                               int roll(int max)
                                                               {
                                                                   int roll;
                                                                      roll = rand() % max + 1;
                                                                        
                                                                            return roll;
                                                                            }
                                                                             
                                                                             void down(int* pt,int n)
                                                                             {
                                                                                 int i, j;
                                                                                     int temp;
                                                                                      
                                                                                          for(i=0;i<n-1;i++)
                                                                                                  for(j=i+1;j<n;j++)
                                                                                                              if (pt[i] < pt[j])
                                                                                                                          {
                                                                                                                                          temp = pt[i];
                                                                                                                                                          pt[i] = pt[j];
                                                                                                                                                                          pt[j] = temp;
                                                                                                                                                                                     }
                                                                                                                                                                                     }

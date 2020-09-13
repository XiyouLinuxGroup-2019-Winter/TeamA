#include <stdlib.h>
#include <stdio.h>

typedef struct file
{
    int flag;
    int sender;
    int recver;
    int file_size;
    char file_name[100];
    char data[800];
}file_t;
int main()
{
  file_t file;
  printf("sizeof=%ld\n",sizeof(file));
  printf("sizeof=%ld\n",sizeof(file_t));
   // printf("\033[;36m\33[1m hais");
  // printf("\33[1m js");
}
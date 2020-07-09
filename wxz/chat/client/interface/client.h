#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
typedef struct person_account
{
    int flag;
    char name[30];
    char password[30];
    char phone[30];
    char e_mail[50];
}account;

typedef struct person_account_find
{
    int flag;
    char name[30];
    char password[30];
    char phone[30];
    char e_mail[50];
}account_find;

/*typedef struct package
{

};*/
void Clear_buffer();
void Login_menu();
void Register();
void Login();
void Modify_password();

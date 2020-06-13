typedef struct PERSON
{
    int num;
    int age;
    char name[20];
    char phone[50];
    char come[100];
    char thing[100];
    struct PERSON*next;
}PERSON;

char 
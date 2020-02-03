#include<stdio.h>
#define ARTICHOKE 2.05f
#define BEET 1.15f
#define CARROT 1.09f
#define DISCOUNT_M 100
#define DISCOUNT_R 0.05
#define FARE_P_1 5
#define FARE_P_2 20
#define FARE_1 6.5
#define FARE_2 14
#define FARE_OT 0.5
int main(void)
{
    char goods, ch;
    float a_pound = 0;
    float b_pound = 0;
    float c_pound = 0;
    float pound, total_pound;
    float fare, total_cost;
    float discount = 0;
    float a_cost, b_cost, c_cost;
    _Bool re;
 
    do
    {
        re = 0;
        printf("*****************************************\n");
        printf("Please select the goods you need.\n");
        printf("a. artichoke\nb. beet\nc. carrot\n\n");
        printf("Your choice: ");
        goods = getchar();
        getchar();
        switch (goods)
        {
        case 'a':
            printf("Artichoke weight(pound): ");
            scanf("%f", &pound); getchar();
            a_pound += pound;
        break;
        case 'b':
            printf("Beet weight(pound): ");
            scanf("%f", &pound); getchar();
            b_pound += pound;
            break;
        case 'c':
            printf("Carrot weight(pound): ");
            scanf("%f", &pound); getchar();
            c_pound += pound;
            break;
        default:
            printf("\nPlease enter the correct letter.\n");
            re = 1; break;
        }
        if (re != 1)
        {
            printf("\nDo you want to select another goods?\n");
            printf("Y.yes\t\tN.no\n");
            while ((ch = getchar()) != 'Y' && ch != 'N')
            {
                getchar();
                printf("Please enter correct letter.\n");
            }
            if (ch == 'Y')
            {
                getchar();
                re = 1;
            }
            else
                printf("\nThank you for purchase.\n\n");
        }
    } while (re == 1);
 
    a_cost = a_pound * ARTICHOKE;
    b_cost = b_pound * BEET;
    c_cost = c_pound * CARROT;
    total_cost = a_cost + b_cost + c_cost;
    total_pound = a_pound + b_pound + c_pound;
    if (total_cost >= DISCOUNT_M)
        discount = DISCOUNT_M * DISCOUNT_R;
    if (total_pound <= 5)
        fare = 6.5f;
    else if (total_pound <= 20)
        fare = 14.0f;
    else
        fare = 14.0f + (total_pound - 14) * 0.5f;
 
    printf("%30s  %15s  %15s  %15s\n","Goods:","Artichoke","Beet","Carrot");
    printf("%30s  %15s  %15s  %15s\n","Price(/pound):","2.05","1.15","1.09");
    printf("%30s  %15.2f  %15.2f  %15.2f\n", 
        "Ordered weight(pound):",a_pound, b_pound, c_pound);
    printf("%30s  %15.2f  %15.2f  %15.2f\n",
        "Cost:",a_cost, b_cost, c_cost);
    printf("%30s  %.2f\n", "Total cost:", total_cost);
    printf("%30s  %.2f\n", "Discount:", discount);
    printf("%30s  %.2f\n", "Freight and packing charges:", fare);
    printf("%30s  %.2f\n", "Total payment:",total_cost - discount + fare);
 
    return 0;
}

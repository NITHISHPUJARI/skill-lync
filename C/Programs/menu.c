#include <stdio.h>

int main()
{
    // menu items
    char item1[] = "Cheeseburger";
    char item2[] = "Fries";
    char item3[] = "Chicken_Sandwich";
    char item4[] = "Salad";
    char item5[] = "Soft_Drink";

    // prices
    float price1 = 160.4;
    float price2 = 65.8;
    float price3 = 220.47;
    float price4 = 134.4;
    float price5 = 36.5;

    // display menu
    printf("Menu\n");
    printf("1. %s - Rs. %.2f\n", item1, price1);
    printf("2. %s - Rs. %.2f\n", item2, price2);
    printf("3. %s - Rs. %.2f\n", item3, price3);
    printf("4. %s - Rs. %.2f\n", item4, price4);
    printf("5. %s - Rs. %.2f\n", item5, price5);

    // ask user for order
    int order[5] = {0};
    printf("Enter the numbers of the items you want to order (separated by spaces): ");
    scanf("%d %d %d %d %d", &order[0], &order[1], &order[2], &order[3], &order[4]);
    getchar();

    // compute total price
    float total = 0.0;
    for (int i = 0; i < 5; i++)
    {
        if (order[i] == 1)
        {
            total += price1;
        }
        else if (order[i] == 2)
        {
            total += price2;
        }
        else if (order[i] == 3)
        {
            total += price3;
        }
        else if (order[i] == 4)
        {
            total += price4;
        }
        else if (order[i] == 5)
        {
            total += price5;
        }
    }

    // display order and total price
    printf("Your order: ");
    for (int i = 0; i < 5; i++)
    {
        if (order[i] != 0)
        {
            printf("%s ", i == 0 ? item1 : i == 1 ? item2 : i == 2 ? item3 : i == 3 ? item4 : item5);
        }
    }
    printf("\n");
    float GST = (total * 0.05);
    printf("Total price: Rs. %.2f\n", total);
    printf("5%% Gst is: Rs. %.2f\n", GST); 
    float result = total + (total * 0.05);
    printf("Final price with GST: Rs. %.2f\n", result);

    return 0;
}

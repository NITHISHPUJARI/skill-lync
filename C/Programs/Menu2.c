#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    
char menu;
float total = 0.0;
char operation[40];
int number_of_operations = 0;

while(1) {

printf("\n\n WELCOME TO THE Platform 65 \n\n");
printf("Here is our menu \n\n");

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
    printf("5. %s - Rs. %.2f\n\n", item5, price5);

printf("Press 'a' for CheeseBurger \n");
printf("Press 'b' for Fries \n");
printf("Press 'c' for Chicken_sandwich \n");
printf("Press 'd' for Salad \n");
printf("Press 'e' for SoftDrink \n");

printf("Press 'q' to Close the menu \n");

printf("Waiting for your Input \n");

scanf("%c", &menu);

switch (menu)
{
	default:
        printf("Invalid input. Please try again.\n");
        break;

	case 'a':
		printf("Selected %s : %.2f \n ", item1, price1);
        total += price1;

		strcpy(operation, "Addition");
		number_of_operations++;
		printf("\n****KPI STATS******\n");
        printf("Last operation performed is %s\n", operation);
        printf("Total no of operations = %d\n", number_of_operations);
		printf("\n\n ***********************************\n");
		printf("\nAnything Else\n"); 
		while(getchar() != '\n'); 
		getchar(); 
        break;
		
	case 'b':
	    printf("****Performing Multiplication****** \n");
	    int mul_number, mul_num;
		int mul=1;
		printf("Enter the number of elements you want to Multiplication: ");
		scanf("%d", &mul_number);
		printf("Please enter %d numbers one by one: \n " , mul_number);
		
		for (int i=1; i<=mul_number; i++){ 
			
			scanf("%d", &mul_num);
			mul *= mul_num; }
			
		printf("Multiplication of %d numbers =  %d" , mul_number, mul);
		strcpy(operation, "Multiplication");
		number_of_operations++;
		printf("\n****KPI STATS******\n");
        printf("Last operation performed is %s\n", operation);
        printf("Total no of operations = %d\n", number_of_operations);
		printf("\n\n***********************************\n");
		printf("\nPress enter to reset the operation..."); 
		while(getchar() != '\n'); 
		getchar(); 
	 	break;
	
	case 'c':
	    printf("****Performing Increment****** \n");
	    int num_times, inc_num;
		int intial_num;
		printf("Enter the intial number: ");
		scanf("%d", &intial_num);
		printf("Enter the number of times you want to Increment: ");
		scanf("%d", &num_times);
		printf("Please enter the number by which you need to be incremented: \n ");
		scanf("%d", &inc_num);
		
		for (int i=1; i<=num_times; i++){ 
			
			intial_num += inc_num;
			 }
			
		printf("Incrementation of %d numbers =  %d" , num_times, intial_num);
		strcpy(operation, "Increment");
		number_of_operations++;
		printf("\n****KPI STATS******\n");
        printf("Last operation performed is %s\n", operation);
        printf("Total no of operations = %d\n", number_of_operations);
		printf("\n\n***********************************\n");
		printf("\nPress enter to reset the operation..."); 
		while(getchar() != '\n'); 
		getchar(); 
	 	break;
	
	case 'd':
	    printf("****Performing Modulus****** \n");
	    int numerator, denominator;
		int remainder=0;
		printf("Enter the numerator: ");
		scanf("%d", &numerator);
		printf("Enter the denominator: ");
		scanf("%d", &denominator);

		remainder = (numerator%denominator);
			
		printf("Remainder for %d modulus %d is :   %d" , numerator, denominator, remainder);
		strcpy(operation, "Modulus");
		number_of_operations++;
		printf("\n****KPI STATS******\n");
        printf("Last operation performed is %s\n", operation);
        printf("Total no of operations = %d\n", number_of_operations);
		printf("\n\n***********************************\n");
		printf("\nPress enter to reset the operation..."); 
		while(getchar() != '\n'); 
		getchar(); 
	 	break;

	case 'e':
	    printf("****Performing Right Shift****** \n");
	    int From_value, To_value;
		int Final_value=0;
		printf("Enter the From_value: ");
		scanf("%d", &From_value);
		printf("Enter the To_value: ");
		scanf("%d", &To_value);
		
		Final_value = From_value >> To_value;
			
		printf("Right shift from %d to %d is :  %d" , From_value, To_value, Final_value);
		strcpy(operation, "Right Shift");
		number_of_operations++;
		printf("\n****KPI STATS******\n");
        printf("Last operation performed is %s\n", operation);
        printf("Total no of operations = %d\n", number_of_operations);
		printf("\n\n***********************************\n");
		printf("\nPress enter to reset the operation..."); 
		while(getchar() != '\n'); 
		getchar(); 
	 	break;

    case 'q':
        printf("Closing the Menu. Thank You!\n");
        exit(0);
        break;
}
}
printf("\n****KPI STATS******\n");
        printf("Last operation performed is %s\n", operation);
        printf("Total no of operations = %d\n", number_of_operations);
		printf("\n\n ***********************************\n");
		printf("\nPress enter to reset the operation...");
		operation[0] = '\0'; 
number_of_operations = 0; 
return 0;
}
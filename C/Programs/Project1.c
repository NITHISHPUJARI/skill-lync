#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    

char Platform;
char operation[40];
int number_of_operations = 0;

while(1) {

printf("\n\n WELCOME TO THE LTE PLATFORM SERVICES \n\n");
printf("Enter the desired extension to get service from platform: \n");
printf("Press 'a' for Addition \n");
printf("Press 'b' for Multiplication \n");
printf("Press 'c' for Increment \n");
printf("Press 'd' for Modulus \n");
printf("Press 'e' for Right shift \n");
printf("Press 'f' for left shift \n");
printf("Press 'g' for power \n");
printf("Press 'h' for AND operation \n");
printf("Press 'i' for OR operation \n");
printf("Press 'j' to Count no of set bits \n");
printf("Press 'k' to show kpi stats \n\n");
printf("Press 'q' to Shutdown the platform \n");

printf("Waiting for your Input \n");

scanf("%c", &Platform);


switch (Platform)
{
	default:
        printf("Invalid input. Please try again.\n");
        break;

	case 'a':
		printf("****Performing Addition****** \n ");
		int add_number, add_num;
		int add=0;
		printf("Enter the number of elements you want to add: ");
		scanf("%d", &add_number);
		printf("Please enter %d numbers one by one: \n " , add_number);
		
		for (int i=1; i<=add_number; i++){ 
			
			scanf("%d", &add_num);
			add += add_num; }
			
		printf("Addition of %d numbers =  %d" , add_number, add);
		strcpy(operation, "Addition");
		number_of_operations++;
		printf("\n****KPI STATS******\n");
        printf("Last operation performed is %s\n", operation);
        printf("Total no of operations = %d\n", number_of_operations);
		printf("\n\n ***********************************\n");
		printf("\nPress enter to reset the operation..."); 
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

	case 'f':
	    printf("****Performing Left Shift****** \n");
	    int Right_value, Left_value;
		int End_value=0;
		printf("Enter the From_value: ");
		scanf("%d", &Right_value);
		printf("Enter the To_value: ");
		scanf("%d", &Left_value);
		
		End_value = Left_value << Right_value;
			
		printf("Right shift from %d to %d is :  %d" , Right_value, Left_value, End_value);
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

	case 'g':
	    printf("****Performing Power****** \n");
	    int base_value, power_value;
		int result=1;
		printf("Enter the base_value: ");
		scanf("%d", &base_value);
		printf("Enter the power_value: ");
		scanf("%d", &power_value);
		
		result = pow(base_value, power_value);
			
		printf("Power value of %d to the %d is :  %d" , base_value, power_value, result);
		strcpy(operation, "Power");
		number_of_operations++;
		printf("\n****KPI STATS******\n");
        printf("Last operation performed is %s\n", operation);
        printf("Total no of operations = %d\n", number_of_operations);
		printf("\n\n***********************************\n");
		printf("\nPress enter to reset the operation...");
		while(getchar() != '\n'); 
		getchar(); 
	 	break;

	case 'h':
	    printf("****Performing AND operation****** \n");
	    int value1_and, value2_and;
		int output_and = 0;
		printf("Enter the intial_value: ");
		scanf("%d", &value1_and);
		printf("Enter the final_value: ");
		scanf("%d", &value2_and);
		
		output_and = value1_and & value2_and ;
			
		printf("AND operation of %d and %d numbers is :  %d" , value1_and, value2_and,  output_and);
		strcpy(operation, "AND operation");
		number_of_operations++;
		printf("\n****KPI STATS******\n");
        printf("Last operation performed is %s\n", operation);
        printf("Total no of operations = %d\n", number_of_operations);
		printf("\n\n***********************************\n");
		printf("\nPress enter to reset the operation...");
		while(getchar() != '\n'); 
		getchar(); 
	 	break;

	case 'i':
	    printf("****Performing OR operation****** \n");
	    int value1_or, value2_or;
		int output_or = 0;
		printf("Enter the intial_value: ");
		scanf("%d", &value1_or);
		printf("Enter the final_value: ");
		scanf("%d", &value2_or);
		
		output_or = value1_or | value2_or ;
			
		printf("OR operation of %d and %d numbers is :  %d" , value1_or, value2_or,  output_or);
		strcpy(operation, "OR operation");
		number_of_operations++;
		printf("\n****KPI STATS******\n");
        printf("Last operation performed is %s\n", operation);
        printf("Total no of operations = %d\n", number_of_operations);
		printf("\n\n***********************************\n");
		printf("\nPress enter to reset the operation...");
		while(getchar() != '\n'); 
		getchar(); 
	 	break;

	case 'j':
	    printf("****Performing Count no of set bits operation****** \n");
			
		printf("I am unable to perform the set bits operation right now,\n Sorry for inconvenience caused\n You Can Try other operations\n ");
		strcpy(operation, "Count no of set bits operation");
		number_of_operations++;
		printf("\n****KPI STATS******\n");
        printf("Last operation performed is %s\n", operation);
        printf("Total no of operations = %d\n", number_of_operations);
		printf("\n\n***********************************\n");
		printf("\nPress enter to reset the operation...");
		while(getchar() != '\n'); 
		getchar(); 
	 	break; 

	case 'k':
        printf("****KPI STATS******\n");
        printf("Last operation performed is %s\n", operation);
        printf("Total no of operations = %d\n", number_of_operations);
		printf("***********************************\n");
		printf("\nPress enter to reset the operation...");
		while(getchar() != '\n'); 
		getchar(); 
        break;

    case 'q':
        printf("Shutting down the LTE platform services. Goodbye!\n");
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
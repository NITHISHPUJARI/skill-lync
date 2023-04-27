// C Program to demonstrate Structure pointer
#include <stdio.h>
#include <string.h>
// Struct for Holding Student Data
struct Student {
	int roll_no;
	char name[30];
	char branch[40];
	int batch;
};

int main()
{

	struct Student student1;
    // Structure Ponter:
	struct Student* StudentPtr = &student1;

    // Fill data into Struct:
	student1.roll_no = 34;
	strcpy(student1.name, "Akshay Varpe");
	strcpy(student1.branch, "Electronics & Telecommunication");
	student1.batch = 2017;

    printf("Display The Data:\r\n");
    // Access structure members using the structure pointer with the help of the dot operator.
	printf("Roll Number: %d\r\n", (*StudentPtr).roll_no);
	printf("Name: %s\r\n", (*StudentPtr).name);
    // Access the structure members using the structure pointer with the help of the Arrow operator.
	printf("Branch: %s\r\n", StudentPtr->branch);
	printf("Batch: %d\r\n", StudentPtr->batch);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a structure called car
struct Car
{
    char brand[50]; // string (char array) Member
    char model[50]; // string (char array) member
    int year;       // int variable
    float milage;   // float variable
} car1,car4;        // variable decleration along with structure

// Create a Nested Structure called RegDetails
struct RegDetails
{
    int VehilceID;
    char RegNum[12];
    struct Car VehicleInfo; // struct Car as a member of RegDetails
} RegCar;   // Variable for RegDetails


// function prototype
struct Car FuncGetCar();                  // Function to return structure item  
void FuncDisplayCar(struct Car s);        // Function with Structure as argument
void FuncFillCarDetaials(struct Car details, struct Car * s); // Passing struct by reference

int main()
{
    struct Car car2 = {"BMW", "X5", 1999, 15.3}; // struct varabile declaration along with values
    struct Car car3 = {"Ford", "Mustang", 1969, 10.6};
    struct Car car5, carCopy;   // sruct variable declaration
    struct Car CarList[5];      // Array of structure    
    // Assign values to members of car1
    car1.year = 2011;       // Asign int value
    car1.milage = 21.5;     // Asign float value

    // Remember that strings in C are actually an array of characters, 
    // and unfortunately, you can't assign a value to an array like this:
    // s1.myString = "Some text";
    // Assign a value to the string using the strcpy & strncpy functions
    strcpy(car1.brand, "Toyota");

    strncpy(car1.model, "Corolla", 7);
    // While using strncpy( ) in the example,
    // We have explicitly added terminating null character '\0' in the last place as follow:
    car1.model[7] = '\0';
    // This is done because we have only copied first 7 characters
    // and there is no terminating null character at the end of character array car1.model.
    
    // Copy Structures:
    carCopy = car1;

    // We can also use structure to functions:
    // You can return structure from a function:
    car4 = FuncGetCar();

    // You can pass structure to a function py value & by reference 
    FuncFillCarDetaials(car1, &car5);

    //Print the values of structures using function:
    printf("Print all the assigned values:\r\n");
    FuncDisplayCar(car1);
    FuncDisplayCar(car2);
    FuncDisplayCar(car3);
    FuncDisplayCar(car4);
    FuncDisplayCar(car5);
    printf("\r\ncarCopy: \r\n");
    FuncDisplayCar(carCopy);

    // We can also create array of structure: 
    CarList[0] = car1;  // Assign Copy car1 value to CarList[0]
    CarList[1] = car2;
    CarList[2] = car3;
    CarList[3] = car4;
    CarList[4] = car5;
    
    printf("\r\nPrint the CarList:\r\n");
    //Print the Struct array:
    for(int i = 0; i < 5 ; i++)
    {
        printf("CarList[%d]:\r\n", i);
        FuncDisplayCar(CarList[i]);
    }

    // Assign value of Nested Structure variable:
    RegCar.VehilceID = 12;
    strcpy(RegCar.RegNum, "MH12LX4122");
    RegCar.VehicleInfo = car2;  // Copy Car info from car2 to RegCar.VehicleInfo
    printf("\r\nNested Struct:\r\n");
    printf("RegCar.VehilceID = %d\r\n", RegCar.VehilceID);
    printf("RegCar.RegNum    = %s\r\n", RegCar.RegNum);
    FuncDisplayCar(RegCar.VehicleInfo);
    return 0;
}


// This function will retrun the structure that is pre filled inside it
struct Car FuncGetCar()
{
    struct Car carEntry = {"Maruti", "Swift", 2019, 28.5};

    return carEntry;    // Return the struct value
}

// Function with Structure as argument
// Function will print the values of members from the structures
void FuncDisplayCar(struct Car s)
{
    printf("Brand=%s\tModel=%s\tYear=%d\tMilage=%f\r\n", s.brand, s.model, s.year, s.milage);
}        

// Passing struct by reference
// This function will assign the values to the structure passed by reff
void FuncFillCarDetaials(struct Car details, struct Car * s)
{
    s->year = details.year; // Assign the value to sruct argument passed by reference
    s->milage = details.milage;
    strcpy(s->brand, details.brand);
    strcpy(s->model, details.model);
}
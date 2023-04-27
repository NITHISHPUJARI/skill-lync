#include <iostream>
using namespace std;
class Base_A
{
public:
    void print_info() // function that call display
    {
        display();
    }
    void display() // the display function
    {
        cout << "Printing from the Base_A class" << endl;
    }
};
class Derived_B : public Base_A // Derived_B inherit a publicly
{
public:
    void display() // Derived_B's display function
    {
        cout << "Printing from the Derived_B class" << endl;
    }
};
int main()
{
    Base_A obj1;        // Creating Base_A's pbject
    obj1.print_info(); // Calling final_print
    Derived_B obj2;     // Creating Derived_B
    obj2.print_info();
    return 0;
}
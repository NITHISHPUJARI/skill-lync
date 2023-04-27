#include <stdio.h>

struct employee {
    char name[50];
    int empId;
    float salary;
    int married;
};

int main() {
    struct employee emp;

    printf("Enter name: ");
    scanf("%s", emp.name);
    printf("Enter employee ID: ");
    scanf("%d", &emp.empId);
    printf("Enter salary: ");
    scanf("%f", &emp.salary);
    printf("Is the employee married? (1 for yes, 0 for no): ");
    scanf("%d", &emp.married);

    printf("\nEmployee details:\n");
    printf("Name: %s\n", emp.name);
    printf("Employee ID: %d\n", emp.empId);
    printf("Salary: %.2f\n", emp.salary);
    printf("Married: %s\n", emp.married ? "Yes" : "No");

return 0;
}
// C program for variable length members in
// structures in GCC
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// A structure of type Book
struct Book
{
    int book_cost;
    int name_len;

    // This is used to store size of flexible
    // character array book_name[]
    int struct_size;

    // Flexible Array Member(FAM)
    // variable length array must be last
    // member of structure
    char book_name[];
};

// Memory allocation and initialisation of structure
struct Book *createBook(struct Book *s, int id, char a[])
{
    // Allocating memory according to user provided
    // array of characters
    s = malloc(sizeof(*s) + (sizeof(char) * strlen(a)));

    s->book_cost = id;
    s->name_len = strlen(a);
    strcpy(s->book_name, a);

    // Assigning size according to size of stud_name
    // which is a copy of user provided array a[].
    s->struct_size =
        (sizeof(*s) + sizeof(char) * strlen(s->book_name));

    return s;
}

// Print student details
void printBook(struct Book *s)
{
    printf("Book_cost : %d\r\n"
           "Book_Name : %s\n\n"
           "Name_Length: %d\r\n"
           "Allocated_Struct_size: %d\r\n\r\n",
           s->book_cost, s->book_name, s->name_len,
           s->struct_size);

    // Value of Allocated_Struct_size is in bytes here
}


int main()
{
    struct Book *s1 = createBook(s1, 1000, "Small World by Laura Zigman (Jan. 10)");
    struct Book *s2 = createBook(s2, 2000, "Maame by Jessica George (Feb. 7)");

    printBook(s1);
    printBook(s2);

    // Size in struct student
    printf("Size of Struct Book: %lu\r\n",
           sizeof(struct Book));

    // Size in struct pointer
    printf("Size of Struct pointer: %lu\r\n",
           sizeof(s1));

    return 0;
}

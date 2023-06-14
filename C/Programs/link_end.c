#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nextNodeAdd;
};

struct Node *createNewNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    (*newNode).data = data;
    (*newNode).nextNodeAdd = NULL;
    return newNode;
}

void end_link(struct Node **head, int data)
{
    struct Node *newNode = createNewNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while ((*temp).nextNodeAdd != NULL)
        {
            temp = (*temp).nextNodeAdd;
        }
        (*temp).nextNodeAdd = newNode;
    }
}


int main()
{
    struct Node *head = NULL;
    
    int size;
    
    printf("Enter the No of elemets to be Printed: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter the elemets to be Printed: ");
    for (int i = 0; i< size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for(int i = 0; i< size; i++)
    {
        end_link(&head, arr[i]);
    }

    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", (*temp).data);
        temp = (*temp).nextNodeAdd;
    }
    printf("\n");

    return 0;
}
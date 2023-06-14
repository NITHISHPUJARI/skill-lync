#include <stdio.h>
#include <stdbool.h>

void Union(int arr1[], int size1, int arr2[], int size2)
{
    int uArr[100], k = 0;
    bool same;

    for (int i = 0; i < size1; i++)
    {
        uArr[k++] = arr1[i];
    }

    for (int i = 0; i < size2; i++)
    {
        same = 0;
        for (int j = 0; j < size1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                same = true;
                break;
            }
        }
        if (same == false)
        {
            uArr[k++] = arr2[i];
        }
    }

    printf("Union of the two arrays: ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", uArr[i]);
    }
}

int main()
{
    int arr1[100], arr2[100], size1, size2;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < size1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < size2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    Union(arr1, size1, arr2, size2);

    return 0;
}
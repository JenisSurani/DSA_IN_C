#include <stdio.h>

void printarray(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

void selectionsort(int *ptr, int size)
{
    int indexofmin, temp;
    for (int i = 0; i < size - 1; i++)  // loop for no of passes
    {
        indexofmin = i;  // variable that will store the index of min element of the unsoretd subarray first it will store the index of the first element
        for (int j = i+1; j < size; j++)  // loop for comparing the indexofmin element to others 
        {
            if (ptr[j] < ptr[indexofmin])
            {
                indexofmin = j;  // update indexofmin if you find any min number
            }
        }

        temp = ptr[i];
        ptr[i] = ptr[indexofmin];  // swaping
        ptr[indexofmin] = temp;
    }
}

int main()
{
    int arr[] = {11, 22, 33, 44,77,66};
    int size = sizeof(arr) / sizeof(int);
    printarray(arr, size);
    selectionsort(arr, size);
    printarray(arr, size);
    return 0;
}

/*
Authour:Jenish Surani
Purpose: Selection Sort
Date: 09/08/2024
*/
#include <stdio.h>

void printarray(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

void inserionsort(int *ptr, int n)
{
    // for loop for number of passes
    for (int i = 1; i <= n - 1; i++) // start the loop at index =1 bcz index=0 is already sorted
    {
        int key = ptr[i]; // storing the element that we wan't to insert
        int j = i - 1;    // index for comparing the element with sorting subarray (just before the key element)

        while (ptr[j] > key && j >= 0) // check- j is index and min index is 0 index -1 is not allowed
        {
            ptr[j + 1] = ptr[j]; // shift the element
            j--;
        }

        ptr[j + 1] = key; // add key just behind the lower number
    }
}
int main()
{
    int arr[] = {11, 22, 33, 44, 77, 66, 002};
    int size = sizeof(arr) / sizeof(int);

    printarray(arr, size);
    inserionsort(arr, size);
    printarray(arr, size);

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Insertion Sort
Date: 09/08/2024
*/
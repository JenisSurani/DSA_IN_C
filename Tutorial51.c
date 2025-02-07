#include <stdio.h>
#include <stdlib.h>

void printarray(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
}

void bubblesort(int *arr, int size)
{
    int temp;

    for (int i = 0; i < size - 1; i++) // no of passes
    {
        printf("Working on %d pass\n", i + 1);

        for (int j = 0; j < size - 1 - i; j++) // no of comparision
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
} //--> Time complexity = O(n^2);

void bubblesortAdaptive(int *arr, int size)
{
    int temp;
    int issorted = 0;
    for (int i = 0; i < size - 1; i++) // no of passes
    {
        
        issorted = 1;
        printf("Working on %d pass\n", i + 1);
        for (int j = 0; j < size - 1 - i; j++) // no of comparision
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
        // i am checking after every pass array is sorted or not?
    }
} //--> Time complexity = O(n);

int main()
{
    int arr[] = {22,11,33,44,23,55,-40};
    int size = sizeof(arr) / sizeof(int);

    printarray(arr, size); // before the bubule sort
    printf("\n");
    bubblesortAdaptive(arr, size);

    printarray(arr, size); // after the bubule sort

    return 0;
}
/*
Authour:Jenish Surani
Purpose: Bubble sort
Date: 08/08/2024
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printarray(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

int maxNUMBER(int A[], int size)
{
    int MAX = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (MAX < A[i])
        {
            MAX = A[i];
        }
    }
    return MAX;
}
void countsort(int A[], int size)
{
    int i, j;
    int maxNum = maxNUMBER(A, size);                        // finding max num of the array
    int *count = (int *)malloc((maxNum + 1) * sizeof(int)); // creating count array

    // initiliaze of all elements of the count array with zero
    for (i = 0; i < maxNum + 1; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < size; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0, j = 0;

    while (i != maxNum + 1)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
    free(count);
}

int main()
{
    int arr[] = {6, 13, 25, 2, 3, 5, 2, 6, 1};
    int size = sizeof(arr) / sizeof(int);
    printarray(arr, size);
    countsort(arr, size);
    printarray(arr, size);

    return 0;
}

/*
Authour:Jenish Surani
Purpose:Count sort
Date: 12/08/2024
*/
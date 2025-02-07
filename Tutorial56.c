#include <stdio.h>

void printarray(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do // do while tetla mate karan ke ek vkht to aapde loop chalavu j che
    {

        while (A[i] <= pivot && i < high) // while loop opposite condition ley tamare i < pivot pan nahi chale ane i=pivot pan nahi chale je nahi chale te condition ma devanu
        // ahi i=high thase aetle conditon false means ke i high thi aagal nhi jay
        {
            i++;
        }
        while (A[j] > pivot && j >= low) // tamare j>pivot hoy ne te nahi chale
        // ahi j=0 thase aetle pehli condition false aetle j invalid index par nahi jay
        {
            j--;
        }
        if (i < j) // condition for jo i and j ek sthane hoy to final swap karo tem jo i > j thi moto hoy to b final swap karo aetle jo i<j hoy to j element nu swap karo parntu jo i<j false thase means ke final swap karvanu che to do while pan false thase ane final swap thase
        {
            temp = A[i];
            A[i] = A[j]; // elements nu swap
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low]; // final swap
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quicksort(int A[], int low, int high, int size)
{
    if (low < high) // conditon for end of recursion jo ek element no dabbo bachse to low=high false ,, chalse bcz ek elemnt hamesha soreted j hoy recursion call thava mate min 2 element jaruri tem kahe che
    {
        int partionindex;
        partionindex = partition(A, low, high);
        printarray(A, size);                        // harek call baad print karse
        quicksort(A, low, partionindex - 1, size);  // recursion no first part
        quicksort(A, partionindex + 1, high, size); // recutsion mate no second part
    }
}
int main()
{
    int arr[] = {10,7,5};
    int size = sizeof(arr) / sizeof(int);
    printarray(arr, size);
    quicksort(arr, 0, size - 1, size);
    printarray(arr, size);

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Quicksort 
Date: 10/08/2024
*/
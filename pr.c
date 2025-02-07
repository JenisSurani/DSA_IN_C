#include <stdio.h>

void printarray(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
}

void insertionsort(int *arr, int size)
{
    for (int i = 1; i <= size - 1; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void selectionsort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int indexofmin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[indexofmin])
            {
                indexofmin = j;
            }
        }
        int temp;
        temp = arr[i];
        arr[i] = arr[indexofmin];
        arr[indexofmin] = temp;
    }
}

int partiton(int *arr, int low, int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;

    do
    {
        while (arr[i]<=pivot && i<high)
        {
            i++;
        }

        while (arr[j]>pivot && j>=low)
        {
            j--;
        }
        
        if (i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        
        
    } while (i<j);
    
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;

    return j;
}

void quicksort(int arr[], int low, int high, int size)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partiton(arr, low, high);
        quicksort(arr, low, partitionindex - 1, size);
        quicksort(arr, partitionindex + 1, high, size);
    }
}
int main()
{
    int arr[] = {11, 2, 3, 221, 0, 3, 22};
    int size = sizeof(arr) / sizeof(int);

    printarray(arr, size); // before the bubule sort
    printf("\n");
    quicksort(arr,0,size-1, size);

    printarray(arr, size); // after the bubule sort

    return 0;
}
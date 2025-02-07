#include <stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i; // element found  // Travesring full array ---> O(n)
        }
    }
    return -1; // elemnent not found
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    // start searching
    while (low <= high) // last ma mid,high,low=1 thase tyare loop last vkht chalse and loop na end ma kato low=2, high=1 thse ka to low=1,high=0 thse jo element array ma hoy j nahi to
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid; // element found at mid index
        }
        if (arr[mid] < element)
        {
            low = mid + 1; // update low,mid+1 karyu because mid ma to elemnt nthi teni aagal thi search karo because uper if ni condition false thai che tethi aa condition check thai che nai tar return thy gayo hot program
        }
        else
        {
            high = mid - 1; // update high , mid-1 karyu because mid ma to elemnt nthi teni pachal thi search karo because uper if ni condition false thai che tethi aa condition check thai che nai tar return thy gayo hot program
        }
    }
    // ends searching
    return -1; // means element not found -----> O(logn)
}
int main()
{
    int arr[] = {11, 22, 33, 44, 55, 66, 77};                      // sorted array must for binarysearch
    int size = sizeof(arr) / sizeof(int),  element = 44; // arr ma 6(elements) x 4(int ni size)/4(int ni size)= 6(elements)
    int SearchIndex = linearSearch(arr, size, element);
    if (SearchIndex == -1)
    {
        printf("Your element is not found in this array.\n");
    }
    else
    {
        printf("Your element is at position of: %d\n", SearchIndex);
    }
    return 0;
}

/*
Authour:Jenish Surani
Purpose: Linear Vs Binary Search
Date: 21/07/2024
*/
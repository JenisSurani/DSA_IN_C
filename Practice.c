#include <stdio.h>

int Max(int *ptr)
{
    int a,b;
    a=ptr[0];
    for (int i = 1; i < 5; i++)
    {
       
         if(ptr[i]>a)
        {
            b=a;
            a=ptr[i];
        }
        else if(ptr[i]>b)
        {
            b=ptr[i];
        }
        
    }
    return a;
}
int Min(int *ptr)
{
    int a,b;
    a=ptr[0];
    for (int i = 1; i < 5; i++)
    {
        if (ptr[i]<a)
        {
            b=a;
            a=ptr[i];
        }
        
    }
    return a;
}
int main()
{
    int array[5] = { 22, 1,55, 44, 100};
    printf("The max element of the array is %d\n", Max(array));
    printf("The min element of the array is %d\n", Min(array));
    return 0;
}
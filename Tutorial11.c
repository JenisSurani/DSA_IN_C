#include <stdio.h>
void displayarray(int arr[],int cap)
{
    for (int i = 0; i < cap; i++)
    {
        printf("%d ",arr[i]);       // Logic ma gadbad che because jo tame badha element ne khiskavo cho to last element nu shu a2=a3 thayu a3 a3=a4 gayu a4 to as it is j rayu ne have tame size ne -1 karo cho because tame ek element delete karyo che ane have size a3 sudhi j print karse aa for loop ma size+1 karo to be 88 dekhase

        // solution 
        /*
        sol1: kato a4=0 kari do
        sol2: kato indDeletion ma size-1 use karvana bade size use karo jethi a4 ne a5 ni value male dar vakhte a5 ni value 0 hoy te jaruri nathi
        jyare array globally or static int arr[] aa rithe define thay tyare tena remainig elements 0 vade initiliazed thai
        main() na array ma array na remaing element 0 pan hold kare garbage value pan hold kari ske 
        */
    }
    
}

void indDeletion(int arr[],int index,int size)
{
    // Deletion process
    for (int i = index; i <size; i++)
    {
         arr[i]=arr[i+1];
    }
    printf("\n");
    
}
int main()
{
    int arr[20] = {7,8,12,27,88};
    int size = 5;
    int index=2;
    int capacity=20;
    printf("Before Deletion\n");
    displayarray(arr,capacity);

    printf("\nAfter Deletion\n");
    indDeletion(arr,index,size);
    size-=1;
    displayarray(arr,capacity);

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Operatios in array(Deletion)
Date: 20/07/2024
*/
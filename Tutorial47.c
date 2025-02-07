#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

void traversal(struct queue *s1)
{
    printf("Your Queue is:");
    for (int i = 0; i < s1->size; i++)
    {
        printf("%d,", s1->arr[i]);
    }
}
int isfull(struct queue *s1)
{
    return s1->r == s1->size - 1;
}

int isempty(struct queue *s1)
{
    return s1->r == s1->f;
}

void EnqueueR(struct queue *s1, int data)
{
    if (isfull(s1))
    {
        printf("This Queue is full:\n");
    }
    else
    {
        s1->r++;
        s1->arr[s1->r] = data;
        // printf("Enqued element:%d\n", data);
    }
} // --> O(1)

void EnqueueF(struct queue *s1, int data)
{
    if (s1->f == -1)
    {
        printf("No space to insert from the front index\n");
    }
    else
    {

        s1->arr[s1->f] = data;
        s1->f--;
        // printf("Enqued element:%d\n", data);
    }
}

int DequeueF(struct queue *s1)
{
    int a = -1;
    if (isempty(s1))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        s1->f++; // moving f 1 step ahead
        a = s1->arr[s1->f];
        s1->arr[s1->f]=0;
    }
    return a;
    // if it returns -1 that means Dequeue process fails
} //--> O(1)

int DequeueR(struct queue *s1)
{
    if (isempty(s1))
    {
        printf("This Queue is empty\n");
    }

    int val = -1;
    val = s1->arr[s1->r];
        s1->arr[s1->r]=0;
    
    s1->r--;
    // printf("Element %d is removed from the rear index\n");
    return val;
}

int main()
{
    struct queue *s1 = (struct queue *)malloc(sizeof(struct queue));
    s1->size = 4;
    s1->f = s1->r = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(int));

    EnqueueR(s1, 22);
    EnqueueR(s1, 33);
    EnqueueR(s1, 44);
    EnqueueR(s1, 55);

    traversal(s1);
    printf("\n\n");

    DequeueF(s1);

    traversal(s1);
    printf("\n\n");

    EnqueueF(s1, 11);

    traversal(s1);
    printf("\n\n");

    DequeueR(s1);
     traversal(s1);
    printf("\n\n");


    return 0;
}

/*
Authour:Jenish Surani
Purpose: Implementation of DEQueue
Date: 05/08/2024
*/
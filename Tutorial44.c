#include <stdio.h>
#include <stdlib.h>

struct circularqueue
{
    int size;
    int f; // front means index-1 of 1st element
    int r; // roar menas last element index
    int *arr;
};

int isfull(struct circularqueue *s1)
{
    return (s1->r + 1) % s1->size == s1->f;
}

int isempty(struct circularqueue *s1)
{
    return s1->r == s1->f;
}

void Enqueue(struct circularqueue *s1, int data)
{
    if (isfull(s1))
    {
        printf("This circularqueue is full cannot add element %d to queue\n",data);
    }
    else
    {
        (s1->r++) % s1->size;
        s1->arr[s1->r] = data;
        printf("Enqued element:%d\n", data);
    }
}

int Dequeue(struct circularqueue *s1)
{
    int a = -1;
    if (isempty(s1))
    {
        printf("This circularqueue is empty, cannot dequeue from this queue\n");
    }
    else
    {
        (s1->f++) % s1->size; // moving f 1 step ahead
        a = s1->arr[s1->f];
        printf("Dequed Element: %d\n", a);
    }
    return a;
    // if it returns -1 that means Dequeue process fails
}

int main()
{
    struct circularqueue *s1 = (struct circularqueue *)malloc(sizeof(struct circularqueue));
    s1->size = 4;
    s1->f = s1->r = 0; // in circular queue f and r both starts at the 0 if f start with -1 condition for isfull() will never match becuase r never becomes -1;
    // so in circular queue our both index start with zero

    s1->arr = (int *)malloc(s1->size * sizeof(int));

    Enqueue(s1, 22);
    Enqueue(s1, 11);
    Enqueue(s1, 33);

    printf("\n");
    Dequeue(s1);
    Dequeue(s1);
    Dequeue(s1);
 

    Enqueue(s1, 55);
    Enqueue(s1, 44);
    Enqueue(s1, 66);


    // Dequeue(s1);

    // Enqueue(s1, 44);
    // Enqueue(s1, 44);
    // Enqueue(s1, 44);

   if (isfull(s1))
    {
        printf("Queue is full\n");
    }
    if (isempty(s1))
    {
        printf("Queue is empty\n");
    }

    return 0;
}

// we can add only size-1 element in our ciruclar queue because one box (index=0) is reserved for r and f

/*
Authour:Jenish Surani
Purpose: Implementation of circularqueue using array and their operations
Date: 04/08/2024
*/
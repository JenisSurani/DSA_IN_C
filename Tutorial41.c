#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;  // front means index-1 of 1st element
    int r;  // rear menas last element index
    int *arr;
};

int isfull(struct queue *s1)
{
    return s1->r == s1->size - 1;
}

int isempty(struct queue *s1)
{
    return s1->r == s1->f;
}
void Enqueue(struct queue *s1, int data)
{
    if (isfull(s1))
    {
        printf("This Queue is full:\n");
    }
    else
    {
        s1->r++;
        s1->arr[s1->r] = data;
        printf("Enqued element:%d\n",data);
    }
}// --> O(1)

int Dequeue(struct queue *s1)
{
    int a = -1;
    if (isempty(s1))
    {
        printf("This Queue is empty:\n");
    }
    else
    {
        s1->f++; // moving f 1 step ahead
        a = s1->arr[s1->f];
    }
    return a;
    // if it returns -1 that means Dequeue process fails
} //--> O(1)

// in array we don't delete element we just stop  reffering to the element

int main()
{
    struct queue *s1 = (struct queue *)malloc(sizeof(struct queue));
    s1->size = 4;
    s1->f = s1->r = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(int));

    Enqueue(s1, 18);
    Enqueue(s1, 20);
    Enqueue(s1, 22);
    Enqueue(s1, 24);

    printf("%d sucessfully removed from the queue\n", Dequeue(s1));
    // printf("%d sucessfully removed from the queue\n", Dequeue(s1));
    // printf("%d sucessfully removed from the queue\n", Dequeue(s1));
    // printf("%d sucessfully removed from the queue\n", Dequeue(s1));

    // if we add 4 elements and the dequeue all 4 elements from it still it indicates queue is full and queue is empty also becuase at at the end isempty and isfull both condition match
    // Enqueue(s1, 24);

    // and if we try to insert an element it shows queue is full however 4 space is empty

// solution is circular queue

    // if (isfull(s1))
    // {
    //     printf("Queue is full\n");
    // }
    // if (isempty(s1))
    // {
    //     printf("Queue is empty\n");
    // }

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Implementation of queue using array and their operations
Date: 02/08/2024
*/
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct queue *s1)
{
    return s1->r == s1->f;
}
int isfull(struct queue *s1)
{
    return s1->r == s1->size - 1;
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
        // printf("Enqued element:%d\n", data);
    }
} // --> O(1)

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

int main()
{
    struct queue *q;
    q->size = 50;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    int node;
    int i = 6;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    printf("%d ", i);
    visited[i] = 1;
    Enqueue(q, i);

    while (!isempty(q))
    {
        node = Dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                Enqueue(q, j);
            }
        }
    }

    return 0;
}

/*
Authour:Jenish Surani
Purpose: BFS Traversal of graph
Date: 07/09/2024
*/
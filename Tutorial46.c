#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void linkedlisttraversal()
{
    while (f != NULL)
    {
        printf("Element:%d\n", f->data);
        f = f->next;
    }
}

int isfull()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

int isempty()
{
    return f == NULL;
}
void Enqueue(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;

    if (isfull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (f == NULL)
        {
            f = r = n;
        }

        n->next = NULL;
        r->next = n;
        r = n;
    }
}

int Dequeue()
{
    struct node *ptr = f;
    int val = -1;
    if (isempty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{
    printf("Before:\n\n");
    linkedlisttraversal();
    Enqueue(11);
    Enqueue(22);
    Enqueue(33);
    Enqueue(44);
    Enqueue(55);
    printf("After:\n");
    Dequeue();
    Dequeue();
    Dequeue();
    linkedlisttraversal();

    return 0;
}

// Here,when linked-list is empty that means there is no node in linkedlist mens front and rear pointers are pointing to NULL when we assign any one node to linkedlist Front and rear pointer will point this one node and rear pointer goes further with node that we added.

// Here, we initiliazed f and r with gloabl variable becuase our function return type is void and int
// if we want to assign as local variable at that time
//1) Change the retrun type of function to struct node* (that our new head will start follow the this returned head)
//2) Pass the address that any changes made affect the orignal one

/*
Authour:Jenish Surani
Purpose: Implementation of queue using linkedlist
Date: 05/08/2024
*/
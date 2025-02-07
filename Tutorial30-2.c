#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal1(struct node *top)
{
    struct node *ptr = top;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isfull(struct node *ptr)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
     // if dynamically allocated memory is full than heap return null pointer to ptr
    // if ptr is equals to null return 1 that is stack is full
    return p == NULL;
}

int isempty(struct node *ptr)
{
   
    return ptr == NULL;
}

// In push we are linking node with each other
struct node *push(struct node *top, int data)
{
    if (isfull(top))
    {
        printf("Stack Overflow!\n");
        return top;
    }
    else
    {

        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = data;

        ptr->next = top;  // linking each node with each other
        top = ptr;

        return top;
    }
}

int pop(struct node **s1) // give the pointer of struct node*
{
    if (isempty(*s1))  // 8s1 means pointer top no access *s1=top;
    {
        printf("Stack Undeflow!\n");
        return -1;
    }
    else
    {

        struct node *ptr = *s1;
        *s1 = (*s1)->next; 
        int x = ptr->data;
        free(ptr);
        return x;
    }
}

int main()
{
    struct node *top = NULL;

    top = push(top, 33);
    top = push(top, 74);
    top = push(top, 22);
    pop(&top); // call by refrence  
    pop(&top); // call by refrence  
    
// top is pointer of type struct node*

    traversal1(top); 
    return 0;
}

/*
Authour:Jenish Surani
Purpose: Implementation of stack using linkedlist
Date: 29/07/2024
*/
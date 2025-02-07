#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
    struct node *top = NULL;

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

int pop(struct node *s1)
{
    if (isempty(s1))
    {
        printf("Stack Undeflow!\n");
        return -1;
    }
    else
    {

        struct node *ptr = s1;
        top = s1->next; // top is global variable
        int x = ptr->data;
        free(ptr);
        return x;
    }
}

int main()
{
    top = push(top, 33);
    top = push(top, 74);
    top = push(top, 22);
    pop(top); // if top is local variable this throws the error

    // becuase we are passing call by value in pop 
    // any changes in pop function not reflect in main top
    // global variabels ne function ma change karvathi teni actual value ma change thay
    // Soln-2 pass &top and in pop function formal parameter as (struct node ** top) (pointer to pointer)

    traversal1(top);  
    return 0;
}

/*
Authour:Jenish Surani
Purpose: Implementation of stack using linkedlist
Date: 29/07/2024
*/
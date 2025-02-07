#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

int peek(int pos)
{
    struct node *ptr = top;

// postion invalid hase to ptr null ne point kari bese pachi for loop ne agal chalavanu koi matlab nathi
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr!=NULL)
    {
    return ptr->data;
    }
    else{
        return -1;
    }
    
}

int stacktop()
{
    return top->data;
}
int stackbottom()
{
    struct node *ptr = top;
    while (ptr ->next!= NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
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

        ptr->next = top; // linking each node with each other
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
    top = push(top, 11);
    for (int i = 1; i <= 4; i++)
    {
        printf("The value of peek at position %d is :%d\n", i, peek(i));
    }
    printf("The topvalue is %d the bottom value is %d\n", stacktop(), stackbottom());

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Other functions in linkedlist
Date: 30/07/2024
*/
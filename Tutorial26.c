#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr)
{
    return ptr->top == -1;
}
int isfull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("Stack overflow! Element %d cannot be added in stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("\nStack Underflow! Element cannot be popped from the stack\n");
        return -1;
    }
    else
    {
        //instead of removing  we simply decrase top and overwrite our new element when we push
        int val = ptr->arr[ptr->top];
        ptr->top--; 
        return val;
    }
}
int main()
{
    // means s1 aeva dabba na address ne store karse/point karse jema struct stack no maal aavto hoy, aathva to aeva variable na address ne store karse jeno type struct stack hoy.
    // aa syntax aeva dabba ne point kare che je struct stack jetli jagya lese
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1->size = 10;
    s1->top = -1;
    s1->arr = (int *)malloc(sizeof(s1->size * sizeof(int)));

    // printf("Before,Stack is empty?--> %d\n", isempty(s1));
    // printf("Before,Stack is full?--> %d\n\n", isfull(s1));

    push(s1, 46); // 1
    push(s1, 6);  // 2
    push(s1, 16); // 2
    push(s1, 36); // 4
    push(s1, 66); // 5
    push(s1, 76); // 6
    push(s1, 21); // 7
    push(s1, 23); // 8
    push(s1, 43); // 9
    push(s1, 76); // 10  ---> Here Stack is full
    push(s1, 1);  // ---> Element Cannot be added in stack because stack is full (stack overflow)

    // printf("\nAfter,Stack is empty?--> %d\n", isempty(s1));
    // printf("After,Stack is full?--> %d\n\n", isfull(s1));

    for (int i = 0; i < 11; i++)
    {
        int c = pop(s1);
        if (c == -1)
        {

            break;
        }
        printf("Element %d is sucessfully popped from the stack!\n", c);
    }

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Implementation of integer stack (isfull() , isempty(),push() & pop() :)
Date: 27/07/2024
*/
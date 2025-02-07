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
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// peek menas aevu function je -  te position par rahela element ne return karse
// position stack ma upside thi downside count thay
// index stack ma downside thi upside count thay
int peek(struct stack *ptr, int i)
{
    int c = ptr->top - i + 1; // relationship between position and index of the array
    if (c < 0)                // condition to check whether the user enters the correct position or not!
    {
        printf("You Enterd Invalid postion! , Please Enter a valid position");
        return -1;
    }
    else
    {
        return ptr->arr[c]; // returning the value // we convert position to indext to return the value
    }
}

int main()
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1->size = 15;
    s1->top = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(int));

    push(s1, 11);
    push(s1, 22);
    push(s1, 33);
    push(s1, 44);
    push(s1, 55); // index no-4 and position no-1

    // pop(s1);

    // for (int i = 1; i <= s1->top + 1; i++) // if you want to check error make it +2 instead of +1
    // {
    //     int c = peek(s1, i);
    //     if (c < 0)
    //     {
    //         break;
    //     }

    //     printf("The value at position %d of the stack is: %d\n", i,c );
    // }
    printf("%d",peek(s1,4));

    // peek(s1, 5);
    free(s1->arr);
    free(s1);

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Peek operation in stack using array in data structure
Date: 27/07/2024
*/
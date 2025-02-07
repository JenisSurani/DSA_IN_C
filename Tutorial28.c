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

int stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stackbottom(struct stack *ptr)
{
    return ptr->arr[0];
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
    push(s1, 55);

    pop(s1);

    printf("The Top most element of the stack is %d\n", stacktop(s1));
    printf("The Bottom most element of the stack is %d\n", stackbottom(s1));
    free(s1->arr);
    free(s1);

    return 0;
}

/*
Remember one thing accessing an element of the array always take const time
1) In Stacktop --> We are acessing last element of the array(stack)      --> O(1)
2) In Stackbottom --> We are acessing first element of the array(stack)   --> O(1)
3) In Isempty() -->  we are checking top                                  --> O(1)
4) In Isfull()  --> we are checking top                                    --> O(1)
5) In Push  --> We are setting value for top +1                           --> O(1) 
6) IN pop --> we are decrement value of top -1                            --> O(1)
7) In peek --> We are accessing any element for given position            --> O(1)

in all case we are accessing any element of the array and we know that accessing an element of the array always take const time
array tamne badha operation O(1) const time ma run kari ne aape che --> stack using array is best!
*/

/*
Authour:Jenish Surani
Purpose: StackTop & StackBottom operation and all fun's time complexity
Date: 28/07/2024
*/
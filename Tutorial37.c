#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};
char stacktop(struct stack *ptr)
{
    char a = ptr->arr[ptr->top];
    return a;
}
int isempty(struct stack *ptr)
{
    return ptr->top == -1;
}
int isfull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, char val)
{
    if (isfull(ptr))
    {
        printf("Stack overflow! Element %c cannot be added in stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("\nStack Underflow! Element cannot be popped from the stack\n");
        return 0;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char a)
{
    if (a == '*' || a == '/')
    {
        return 3;
    }
    else if (a == '+' || a == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
// computer hamesha left to right j check kare aetle assotivity ni jarur nathi
// aem b postfix and prefix ma checking always left to right j thay

int isOperator(char a)
{
    return a == '+' || a == '-' || a == '*' || a == '/';
}

char *InfixToPostfix(char *infix)
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1->size = 20;
    s1->top = -1;
    s1->arr = (char *)malloc(s1->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; // Track Prefix traversal
    int j = 0; // Track Postfix addition

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stacktop(s1)))
            {
                push(s1, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(s1);
                j++;
            }
        }
    }
    while (!isempty(s1))
    {
        postfix[j] = pop(s1);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c-d/e";
    printf("Postif Expression is: %s\n", InfixToPostfix(infix));
    return 0;
}

/*
Authour:Jenish Surani
Purpose: Infix to Postfix Conversion (Harry)
Date: 02/08/2024
*/
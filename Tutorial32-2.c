 #include <stdio.h>

#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isempty(struct stack *ptr)
{
    return ptr->top == -1;
}

int isfull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct stack *s1, char data)
{
    if (isfull(s1))
    {
        printf("Stack overflow!\n");
    }
    else
    {

        s1->top++;
        s1->arr[s1->top] = data;
    }
}

char pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesisMatch(struct stack *s1, char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(s1, exp[i]);
        }
        if (exp[i] == ')')
        {
            if (isempty(s1))
            {
                return 0;
            }
            pop(s1);
        }
    }
    if (isempty(s1))
    {
        return 1;
    }
    return 0;
}
int main()
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    char string[50];
    printf("Enter your string:\n");
    fgets(string, sizeof(string), stdin);
    s1->size = strlen(string);
    s1->top = -1;
    s1->arr = (char *)malloc(s1->size * sizeof(char));
    if (parenthesisMatch(s1, string))
    {
        printf("Parenthesis matched:)\n");
    }
    else
    {
        printf("Parenthesis not matched:(\n");
    }
    return 0;
}

/*
Authour:Jenish Surani
Purpose: Parenthesis Matching Problem solved by harry
Date: 31/07/2024
*/
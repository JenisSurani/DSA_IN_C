#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

int isfull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

int isempty(struct stack *ptr)
{
    return ptr->top == -1;
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

int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        ptr->top--;
        return 0;
    }
}
int main()
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    char array[50];
    printf("Enter your string:\n");
    fgets(array, sizeof(array), stdin);

    s1->size = strlen(array);
    s1->top = -1;
    s1->arr = (char *)malloc(s1->size * sizeof(char));

    for (int i = 0; i < strlen(array); i++)
    {
        if (array[i] == '(' || array[i] == '{' || array[i] == '[')
        {
            push(s1, array[i]);
        }

        if (array[i] == ')' || array[i] == '}' || array[i] == ']')
        {
            int c = pop(s1);
            if (c == -1)
            {
                printf("Parenthesses Unmatched!\n");
                goto end;
            }
        }
    }

    if (!isempty(s1))
    {
        printf("Parenthesses Unmatched!\n");
    }
    else
    {
        printf("Parenthesses Matched!\n");
    }
end:
    return 0;
}

// You can implement your program more efficient  here is the link of the chatgpt https://chatgpt.com/share/b50cfaed-989f-48c4-993a-7ac7868be206

/*
Authour:Jenish Surani
Purpose: Parenthesses Problem Solved by me(Application of stack!)
Date: 30/07/2024
*/
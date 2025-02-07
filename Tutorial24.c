#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *ptr;
};

int isempty(struct stack* var1)
{
    return (var1->top==-1 ) ? 1 : 0;  // ? : is a ternary operator
  
}
int isfull(struct stack *var2)
{
    return (var2->top==var2->size-1 ) ? 1 : 0;
}

int main()
{
    
    // struct stack *s; // aa vadhare easy pade becuase jo function ma pass karvano thai stack to pointer ne pass kair skaay 
    // means ke tame s banavi didho to teno type juvo struct stack means te aeva dabba ne point karse jeno type struct stack hoy
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1; // -1 represent that stack is empty
    s->ptr = (int *)malloc(s->size * sizeof(int));

    // // s->ptr[0]=7;
    // for (int i = 0; i < s->size; i++)
    // {
    //     printf("Enter %dth element:\n",i);
    //     scanf("%d", &s->ptr[i]);
    //     s->top++;
    // }
    

    if (isempty(s))
    {
        printf("The stack is empty!\n");
    }
    else
    {
        printf("The stack is not empty yet!\n");
    }
    if (isfull(s))
    {
        printf("The stack is full!\n");
    }
    else
    {
        printf("The stack is not full yet!\n");
    }
    free(s->ptr);
    free(s);
    

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Implementation of stack using integers stack (isfull() & isempty() )
Date: 27/07/2024
*/
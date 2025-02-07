#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; // creating of linkedlist via structure
    struct node *next;
};

void linkedlistTraversal(struct node *ptr)
{
    struct node* p=ptr;
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next; // Traversal of linkedlist
    }
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;


    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node)); // Individual blocks banaviye chiye
    third = (struct node *)malloc(sizeof(struct node));  // requesting memory from heap for linkedlist
    fourth = (struct node *)malloc(sizeof(struct node)); // requesting memory from heap for linkedlist

    // Linked first and second node
    head->data = 7;
    head->next = second; // node ne value aapiye chiye

    // Linked second and third node

    second->data = 77; // second->data means *(second)-- means second no dabbo  --.data-- means tema data 7 nakho
    second->next = third;

    //  Linke third and fourth node
    third->data = 777;
    third->next = fourth;

    // Terminate the list at fourth node
    fourth->data = 7777;
    fourth->next = NULL;

    linkedlistTraversal(head);

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Linkedlist Data-Structure (Creation & Traversal)
Date: 21/07/2024
*/
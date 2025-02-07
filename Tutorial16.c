#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1:
struct node *insertAtfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = head;
    head = ptr;
    return head;
}

// Case 2:
struct node *insertAtindex(struct node *head, int index, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3:
struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Case 4:

struct node *insertAtnode(struct node *head, struct node *prevNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    second->data = 77;
    third->data = 777;
    fourth->data = 7777;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    // printf("\nBefore The execution:\n");
    // linkedlisttraversal(head);

    // // head= insertAtfirst(head, 6); // updation of the head // Case-1: O(1)
    // // head = insertAtindex(head, 3, 6); // Case-2: O(n)
    // // head = insertAtEnd(head, 6); // Case-3:  O(n)
    // head = insertAtnode(head, fourth, 6); // Case-4: O(1)

    // printf("\nAfter the execution:\n");
    // linkedlisttraversal(head);

    insertAtindex(head,2,6);
    linkedlisttraversal(head);

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Inserion In LinkedList (  4 cases:)  )
Date: 22/07/2024
*/
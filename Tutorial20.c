#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Traversing
void linklistTraversal(struct node *head)
{
    struct node *ptr = head;
    // while (ptr!=head) // aa condition muki nakhi na sakay because ptr to already head j chene loop exits
    // {
    //     printf("Element: %d\n",ptr->data);
    //     ptr = ptr->next;
    // } // aa loop use karvathi last element print nahi thay

    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head); // ahi condition muki skay because do while loop 1 vakht to farej and ptr update pan thay gayo che
}

// Insertion at first in circluar linklist
struct node *insertionAtfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head;
    do
    {
        p = p->next;
    } while (p->next != head);
    // At that time p is pointing to last element you can also use while loop with ptr->next!=head condition

    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}
// Dlt at last in circular linked list
struct node *dltAtEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }

    p->next = head;
    free(q);

    return head;
} // Prev tutorial ma jya NULL hatu tya head lakhi devanu
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
    fourth->next = head;

    printf("Before:\n");
    linklistTraversal(head);

    head=insertionAtfirst(head,88);
    // head=insertionAtfirst(head,99);
    // head=insertionAtfirst(head,11);
    // head=insertionAtfirst(head,22);  // 22 to 11 to 99 to 88 to 7 to 77.... aem follow thse

    head = dltAtEnd(head);
    printf("\nAfter:\n");
    linklistTraversal(head);

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Insertion and deletion in circular linked list
Date: 24/07/2024
*/
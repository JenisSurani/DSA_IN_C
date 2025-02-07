#include <stdio.h>
#include <stdlib.h>

// Creation of Doubly Linked-List.

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

// Traversing from left to right
void traversal1(struct node *head)
{
    struct node *ptr=head;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Traversing from rigth to left
void traversal2(struct node *fourth)
{
    struct node *ptr=fourth;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

// Insert an element in doubly linked list

struct node *insertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = head;
    ptr->prev = NULL;
    head->prev = ptr;
    // struct node *p = head;
    // while (p->next != NULL)
    // {
    //     p = p->next;
    // }

    // p->next = ptr;
    // ptr->next = head;
    // ptr->prev = NULL;
    // head = ptr;
    // head->prev=ptr;

    head = ptr;

    return head;
}

struct node* dltatfirst(struct node* head)
{
struct node* ptr=head;

head=head->next;
head->prev=NULL;
free(ptr);

return head;
    
}

struct node* dltatend(struct node* head)
{
    struct node* p=head;
    struct node* q=head->next;
    
    while (q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);

    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 11;
    second->data = 22;
    third->data = 33;
    fourth->data = 44;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    fourth->prev = third;
    third->prev = second;
    second->prev = head;
    head->prev = NULL;



    traversal1(head);
    printf("\n");

    // traversal2(fourth);
    // head = insertAtFirst(head, 111);
    // head = dltatfirst(head);
    head = dltatend(head);
    traversal1(head);
    printf("\n");
    printf("\n");

    traversal2(third); // jo tame dltatend use karo cho to ahi update karo karan ke dlt at end use karvathi fourth pointer free thay gayo che ane free thayela pointer ne traversal2(fourth) pass na kari sakay aetle fourth ne badle third ne pass karo.

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Doubly  linked list (Task + Insertion + Deletion)
Date: 24/07/2024
*/
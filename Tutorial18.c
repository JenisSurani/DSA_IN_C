#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linklistTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void l_traversal_reverse(struct node* head)
{
    if (head!=NULL)
    {
    l_traversal(head->next);
    printf("%d ",head->data);
    }
    
}
// Case-1:
struct node *dltAtFirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

// Case-2:
struct node *dltAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *ptr = head;
    int i = 0;
    int j = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    while (j != index)
    {
        ptr = ptr->next;
        j++;
    }
    p->next = ptr->next;
    free(ptr);

    return head;
}

/*// Case-2:

struct node* dltAtIndex(struct node* head,int index)
{
    struct node* p=head;
    struct node* q=head->next;
    int i=0;
    while (i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);

    return head;

}*/

// Case-3:
struct node *dltAtEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

// Case-4;
struct node *DltAtnode(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
        return head;
    }
    else
    {
        printf("Given value is not in linkedlist\n");
    }
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

    printf("Before The execution:\n");
    linklistTraversal(head);

    printf("\nAfter the execution:\n");
    // head = dltAtFirst(head);  // Case-1:----> O(1)
    // head = dltAtIndex(head, 1); // Case-2:---> O(n) // Not applicable for first element at index 0 that means you want to delete at first to first function use karo ne aa function matra given index ne dlt karva banavayu che
    // head= dltAtEnd(head); // Case-3:----> O(n)
    head= DltAtnode(head,777); // Case-4: // not applicable for first element :7 --> O(n)
    linklistTraversal(head);

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Deletion In LinkedList (  4 cases:) first two case me,last two harry )
Date: 22/07/2024
*/
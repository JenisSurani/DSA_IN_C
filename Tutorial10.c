#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};

void traversal(struct node* head)
{
    while (head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    
}

int main()
{
    struct node* head= (struct node*)malloc(sizeof(struct node));
    struct node* second= (struct node*)malloc(sizeof(struct node));
    struct node* third= (struct node*)malloc(sizeof(struct node));
    struct node* fourth= (struct node*)malloc(sizeof(struct node));

    head->data=7;
    second->data=77;
    third->data=777;
    fourth->data=7777;
    
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;

    traversal(head);


    return 0;
}
#include <stdio.h>
// #include <stdlib.h>
#include <malloc.h> // also u can use this library

// create doubly linked list
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
int main()
{
    // Lengthy Construction
    /*
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=3;
    root->left=NULL;
    root->right=NULL;

    struct node* p1=(struct node*)malloc(sizeof(struct node));
    p1->data=33;
    p1->left=NULL;
    p1->right=NULL;

    struct node* p2=(struct node*)malloc(sizeof(struct node));
    p2->data=3;
    p2->left=NULL;
    p2->right=NULL;

    root->left=p1;
    root->right=p2;
    */

    // Easy Construction using function
    struct node *p = createnode(3);
    struct node *p1 = createnode(33);
    struct node *p2 = createnode(333);

    p->left = p1;
    p->right = p2;

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Representation of binary tree using linked representation
Date: 22/08/2024
*/
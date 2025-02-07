#include <stdio.h>
#include <stdlib.h>

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

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node *search(struct node *root,int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data==key)
    {
        return root;
    }
    else if(root->data>key)
    {
        search(root->left,key);
    }
    else
    {
       search(root->right,key);
    }
    
    
}
int main()
{
    struct node *p = createnode(9);
    struct node *p1 = createnode(4);
    struct node *p2 = createnode(2);
    struct node *p3 = createnode(7);
    struct node *p4 = createnode(5);
    struct node *p5 = createnode(8);
    struct node *p6 = createnode(11);
    struct node *p7 = createnode(15);
    struct node *p8 = createnode(14);

    p->left = p1;
    p->right = p6;

    p1->left = p2;
    p1->right = p3;

    p3->left = p4;
    p3->right = p5;
    p6->right = p7;
    p7->left = p8;

    // preorder(p);
    // printf("\n");
    // postorder(p);
    // printf("\n");
    inorder(p);

    struct node* x=search(p,15);
    if (x!=NULL)
    {
        printf("\nFound: %d\n",x->data);
    }
    else
    {
        printf("\nElement not found!\n");
    }
    

    return 0;
}

/*
Authour:Jenish Surani
Purpose: Search in BST using Recursion
Date: 03/09/2024
*/
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

struct node *inOrderPredecessor(struct node *root)
{
    //  inOrderPredecessor means root na left no rightmost child
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    // loop exits means you found the  inOrderPredecessor that is leaf node
    return root;
}
struct node *deletion(struct node *root, int key)
{
    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // Searching for the node
    if (root->data > key)
    {
        root->left=deletion(root->left, key);
    }
    else if (root->data < key)
    {
        root->right=deletion(root->right, key);
    }
    // Deletion Stratergy
    // means you found that element that you want to delete
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left=deletion(root->left, iPre->data);
    }
    return root;
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

    inorder(p);
    printf("\n");
    deletion(p, 7);
    printf("\n");
    inorder(p);

    return 0;
}

/*
Authour:Jenish Surani
Purpose:Deletion in BST
Date: 04/09/2024
*/
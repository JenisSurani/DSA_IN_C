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

int isBST(struct node *root) // this function excatly work as preorder traversal in diff way use recursion braket method and stack method to understand 
// skip if it is confusing 
// ask chatgpt to explain this function in more details and use recursion properly you WIll get it;)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) // violating property of accending order array
        {
            return 0;
        }

        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1; // we consider that empty node is BST
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
    printf("\n");
    if (isBST)
    {
        printf("Given tree is BST\n");
    }
    else
    {
        printf("Given tree is Not BST\n");
    }
    return 0;
}

/*
Authour:Jenish Surani
Purpose: Check given tree is BST or not!
Date: 03/09/2024
*/
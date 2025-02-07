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

void insert(struct node *root, int key)
{
    struct node *prev = NULL;  // jyare root node update thatho thatho leaf node ae pohchse tyare te leaf node na root ne prev point karse ane leaf node ni value valu loop nu iteration chalse tyare prev te place ae aavse jeni tame left ke right insertion kari saksho
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("Duplicate elements not allowed in BST\n");
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createnode(key); // key mate no dabbo banavo
    if (key < prev->data)
    {
        prev->left = new;  // te dabbo nu place aapo
    }
    else
    {
        prev->right = new;
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

    insert(p, 10);
    printf("%d\n", p->right->left->data);

// p->right ni jagya ae p6 mukase
//p6->left aetle new mukase
//new->data aetle 10 print thase

    return 0;
}

// BST ma search aavde aetle badha function easy 

/*
Authour:Jenish Surani
Purpose:Insertion in BST
Date: 04/09/2024
*/



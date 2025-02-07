#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int getHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

// Fix the typo in function name from creatnode to createnode
struct node *createnode(int key)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1; // Leaf node has height 1

    return n;
}

int getBalancefactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node* rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

struct node* leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
    {
        return createnode(key); // Fix here from creatnode to createnode
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int bf = getBalancefactor(node);

    // Left Left Case:
    if (bf > 1 && key < node->left->key)
    {
        return rightrotate(node); // Fix: Should be rightrotate, not leftrotate
    }

    // Right Right Case:
    if (bf < -1 && key > node->right->key)
    {
        return leftrotate(node); // Fix: Correct use of leftrotate
    }

    // Left Right Case:
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftrotate(node->left); // Fix: Change leftrotation to leftrotate
        return rightrotate(node);
    }

    // Right Left Case:
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightrotate(node->right); // Fix: Change rightrotation to rightrotate
        return leftrotate(node);
    }

    return node;
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);

    inorder(root);

    return 0;
}

/*
Author: Jenish Surani
Purpose: AVL Tree Implementation
Date: 04/09/2024
*/

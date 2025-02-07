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
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->key);
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


struct node *createnode(int key)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1; // Because we are creating leaf node and whenever leaf node is connected with another node height of this node becomes one

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
    struct node* y = x->right;
    struct node* T2 = y->left;

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
        return createnode(key);
    }
    if (key < node->key)
    {

        node->left=insert(node->left, key);
    }
    else if (key > node->key)
    {
       node->right = insert(node->right, key);
    }

    // once insertion is done height get reflected

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int bf = getBalancefactor(node);

    // now insertion is done and height and bf is updated
    // now it is the time for the roation stratergy

    // Left Left Case:
    if (bf > 1 && key < node->left->key)
    {
        return rightrotate(node);
    }

    // Right Right Case;
    if (bf < -1 && key > node->right->key)
    {
        return leftrotate(node);
    }
    // Left Right Case;
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    // Right Left Case;

    if (bf < -1 && key < node->right->key)
    {
        node->right = rightrotate(node->right);
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
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    return 0;
}

/*
Authour:Jenish Surani
Purpose: LL RR RL & LR roations in AVL Tress
Date: 09/09/2024
*/

// DSA Complete today
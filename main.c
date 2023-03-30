#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}tree;

void breadthFirstSearch(tree *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        breadthFirstSearch(root->left);
        breadthFirstSearch(root->right);
    }
}





tree *reverseTree(tree *root)
{
    if(root != NULL)
    {
        tree *temp = root->left;
        root->left = root->right;
        root->right = temp;
        reverseTree(root->left);
        reverseTree(root->right);
    }
    return root;
}

tree *newTree(int data)
{
    tree *new = (tree*)malloc(sizeof(tree));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void routeprefixe(tree *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        routeprefixe(root->left);
        routeprefixe(root->right);
    }
}

int isempty(tree *root)
{
    if(root == NULL)
        return 1;
    return 0;
}

int isLeft(tree *root)
{
    if(root->left != NULL)
        return 1;
    return 0;
}

int isRight(tree *root)
{
    if(root->right != NULL)
        return 1;
    return 0;
}

void routeprefixeline(tree *root)
{
    routeprefixe(root);
    printf("\n");
}


int main()
{
    tree* root = newTree(1);
    root->left = newTree(3);
    root->right = newTree(2);
    root->left->left = newTree(6);
    root->left->right = newTree(7);
    root->right->left = newTree(6);
    root->right->right = newTree(7);
    routeprefixeline(root);
    return 0;
}

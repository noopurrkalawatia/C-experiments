//============================================================================
// Name        : bst.cpp
// Author      : Noopur R K
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

struct treeNode
{
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

struct treeNode* newNode(int val)
{
    struct treeNode *temp =  (struct treeNode *)malloc(sizeof(struct treeNode));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct treeNode* insert(struct treeNode* node, int val)
{
    if(node == nullptr)
    {
       return(newNode(val));
    }

    if(node->val < val)
    {
        node->right = insert(node->right,val);
    }

    else if(node->val > val)
    {
        node->left = insert(node->left,val);
    }

    return node;
}

void inorder(struct treeNode* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->val << endl;
        inorder(root->right);
    }
}

int main()
{
    struct treeNode *root = NULL;
       root = insert(root, 50);
       insert(root, 30);
       insert(root, 20);
       insert(root, 40);
       insert(root, 70);
       insert(root, 60);
       insert(root, 80);

       inorder(root);
    return 0;
}

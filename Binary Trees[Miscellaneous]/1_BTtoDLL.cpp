#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
BinaryTreeNode<int> *p = new BinaryTreeNode<int>(-1), *head = new BinaryTreeNode<int>(-1);
void rec(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    rec(root->left);
    if (p->data == -1)
        head = root;
    else
        root->left = p, p->right = root;
    p = root;
    rec(root->right);
}

BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *&root)
{
    p->data = -1, head->data = -1;
    rec(root);
    return head;
}
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

bool validateBST(BinaryTreeNode<int> *&root, int mn = -1e9 - 1, int mx = 1e9 + 1)
{
    if (!root)
        return true;
    if (root->data < mn || root->data > mx)
        return false;
    if (!validateBST(root->left, mn, root->data))
        return false;
    if (!validateBST(root->right, root->data, mx))
        return false;
    return true;
}
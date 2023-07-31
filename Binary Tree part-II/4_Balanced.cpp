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

bool isBalancedBT(BinaryTreeNode<int> *&root, int *height = new int)
{
    if (!root)
        return true;
    int lh = 0, rh = 0;
    if (!isBalancedBT(root->left, &lh) || !isBalancedBT(root->right, &rh))
        return false;
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
        return true;
    return false;
}
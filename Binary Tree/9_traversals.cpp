#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

void traversals(BinaryTreeNode<int> *&root, vector<int> &inorder, vector<int> &preorder, vector<int> &postorder)
{
    if (!root)
        return;
    preorder.push_back(root->data);
    traversals(root->left, inorder, preorder, postorder);
    inorder.push_back(root->data);
    traversals(root->right, inorder, preorder, postorder);
    postorder.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<int> inorder, preorder, postorder;
    traversals(root, inorder, preorder, postorder);
    return {inorder, preorder, postorder};
}
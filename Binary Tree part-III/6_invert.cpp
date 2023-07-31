#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *rec(TreeNode<int> *&root, TreeNode<int> *&leaf)
{
    if (!root)
        return NULL;
    if (root->data == leaf->data)
        return root;
    TreeNode<int> *l = rec(root->left, leaf);
    if (l)
    {
        if (root->left->left)
            root->left->right = root->left->left;
        root->left->left = root;
        root->left = NULL;
        return l;
    }
    TreeNode<int> *r = rec(root->right, leaf);
    if (r)
    {
        if (root->right->left)
            root->right->right = root->right->left;
        root->right->left = root;
        root->right = root->left;
        root->left = NULL;
        return r;
    }
    return NULL;
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *&root, TreeNode<int> *&leaf)
{
    return rec(root, leaf);
}
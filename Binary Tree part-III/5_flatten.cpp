#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure.

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

void flatten(TreeNode<int> *&root)
{
    if (!root)
        return;
    flatten(root->left);
    TreeNode<int> *right = root->right, *temp = root;
    root->right = root->left;
    root->left = NULL;
    while (temp->right)
        temp = temp->right;
    temp->right = right;
    flatten(root->right);
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *&root)
{
    flatten(root);
    return root;
}
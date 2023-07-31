#include <bits/stdc++.h>
/************************************************************
    Following is the Binary Search Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int> *LCAinaBST(TreeNode<int> *&root, TreeNode<int> *&p, TreeNode<int> *&q)
{
    int l = min(p->data, q->data), r = max(p->data, q->data);
    if (!root)
        return nullptr;
    if ((root->data > l && root->data < r) || root->data == l || root->data == r)
        return root;
    if (root->data > r)
        return LCAinaBST(root->left, p, q);
    if (root->data < l)
        return LCAinaBST(root->right, p, q);
    return nullptr;
}

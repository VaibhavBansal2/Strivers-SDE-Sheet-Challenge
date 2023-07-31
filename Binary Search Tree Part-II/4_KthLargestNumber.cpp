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
int kthSmallest(TreeNode<int> *&root, int &k)
{
    if (!root)
        return -1;
    int l = kthSmallest(root->left, k);
    if (!--k)
        return root->data;
    int r = kthSmallest(root->right, k);
    if (l != -1)
        return l;
    return r;
}

int count(TreeNode<int> *&root)
{
    if (!root)
        return 0;
    int c = 1;
    c += count(root->left) + count(root->right);
    return c;
}

int KthLargestNumber(TreeNode<int> *&root, int &k)
{
    k = count(root) - k + 1;
    return kthSmallest(root, k);
}
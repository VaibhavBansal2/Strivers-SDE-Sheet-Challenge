#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> *&root, int &x)
{
    int ans = -1;
    while (root)
        if (x == root->val)
            return x;
        else if (x < root->val)
            root = root->left;
        else
            ans = root->val, root = root->right;
    return ans;
}
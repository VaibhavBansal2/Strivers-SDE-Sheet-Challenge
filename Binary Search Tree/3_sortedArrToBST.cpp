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
TreeNode<int> *bin(vector<int> &nums, int l, int r)
{
    TreeNode<int> *root = nullptr;
    if (l <= r)
    {
        int mid = (l + r) / 2;
        root = new TreeNode<int>(nums[mid]);
        root->left = bin(nums, l, mid - 1);
        root->right = bin(nums, mid + 1, r);
    }
    return root;
}

TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    return bin(arr, 0, n - 1);
}
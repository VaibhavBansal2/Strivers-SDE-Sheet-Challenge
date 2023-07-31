#include <bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

vector<int> getPreOrderTraversal(TreeNode *&root)
{
    vector<int> ans;
    while (root)
        if (!root->left)
            ans.push_back(root->data), root = root->right;
        else
        {
            TreeNode *temp = root->left;
            while (temp->right && temp->right != root)
                temp = temp->right;
            if (!temp->right)
            {
                ans.push_back(root->data);
                temp->right = root;
                root = root->left;
            }
            else
                temp->right = NULL, root = root->right;
        }
    return ans;
}
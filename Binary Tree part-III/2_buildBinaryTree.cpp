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
TreeNode<int> *construct(vector<int> &inorder, vector<int> &preorder, unordered_map<int, int> &ump, int l, int r, int &i)
{
    if (l > r)
        return nullptr;
    TreeNode<int> *root = new TreeNode<int>(preorder[i]);
    int idx = ump[preorder[i]];
    i++;
    root->left = construct(inorder, preorder, ump, l, idx - 1, i);
    root->right = construct(inorder, preorder, ump, idx + 1, r, i);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    unordered_map<int, int> ump;
    for (int i = 0; i < inorder.size(); i++)
        ump[inorder[i]] = i;
    int i = 0;
    return construct(inorder, preorder, ump, 0, inorder.size() - 1, i);
}
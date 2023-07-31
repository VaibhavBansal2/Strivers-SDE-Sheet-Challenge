#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int> *construct(vector<int> &preorder, int l, int r)
{
    if (l > r)
        return nullptr;
    TreeNode<int> *root = new TreeNode<int>(preorder[l]);
    int range = upper_bound(preorder.begin() + l + 1, preorder.begin() + r + 1, preorder[l]) - preorder.begin() - 1;
    root->left = construct(preorder, l + 1, range);
    root->right = construct(preorder, range + 1, r);
    return root;
}

TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    return construct(preOrder, 0, preOrder.size() - 1);
}
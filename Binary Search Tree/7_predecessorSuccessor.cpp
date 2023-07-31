#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void inorder(BinaryTreeNode<int> *&root, vector<int> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *&root, int &key)
{
    vector<int> in;
    inorder(root, in);
    int l = 0, r = in.size() - 1, idx = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (in[mid] == key)
        {
            idx = mid;
            break;
        }
        else if (in[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    pair<int, int> ans = {-1, -1};
    if (idx)
        ans.first = in[idx - 1];
    if (idx < in.size() - 1)
        ans.second = in[idx + 1];
    return ans;
}
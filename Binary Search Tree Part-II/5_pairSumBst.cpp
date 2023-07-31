#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void inorder(BinaryTreeNode<int> *&root, vector<int> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool pairSumBst(BinaryTreeNode<int> *&root, int &k)
{
    vector<int> in;
    inorder(root, in);
    int l = 0, r = in.size() - 1;
    while (l < r)
        if (in[l] + in[r] == k)
            return true;
        else if (in[l] + in[r] > k)
            r--;
        else
            l++;
    return false;
}
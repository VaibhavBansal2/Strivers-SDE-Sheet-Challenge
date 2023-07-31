#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

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
struct node
{
    int size = 0;
    int mn = 1e5 + 1;
    int mx = -1e5 - 1;
    int ans = 0;
    bool isBST = true;
};

node rec(TreeNode<int> *&root)
{
    node ret;
    if (!root)
        return ret;
    if (!root->left && !root->right)
    {
        ret.ans = ret.size = 1;
        ret.mx = ret.mn = root->data;
        return ret;
    }
    node l = rec(root->left), r = rec(root->right);
    ret.size = l.size + r.size + 1;
    ret.mn = min(l.mn, root->data);
    ret.mx = max(r.mx, root->data);
    if (l.isBST && r.isBST && l.mx < root->data && r.mn > root->data)
    {
        ret.ans = ret.size;
        return ret;
    }
    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;
    return ret;
}

int largestBST(TreeNode<int> *&root)
{
    return rec(root).ans;
}
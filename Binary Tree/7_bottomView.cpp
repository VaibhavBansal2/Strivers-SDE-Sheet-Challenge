#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure.

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
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> *root)
{
    map<int, int> mp;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        BinaryTreeNode<int> *node = q.front().first;
        int y = q.front().second;
        mp[y] = node->data;
        q.pop();
        if (node->left)
            q.push({node->left, y - 1});
        if (node->right)
            q.push({node->right, y + 1});
    }
    vector<int> ans;
    for (auto &i : mp)
        ans.push_back(i.second);
    return ans;
}

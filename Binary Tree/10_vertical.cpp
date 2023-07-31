#include <bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *&root)
{
    map<int, vector<int>> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        TreeNode<int> *node = q.front().first;
        int y = q.front().second;
        mp[y].push_back(node->data);
        q.pop();
        if (node->left)
            q.push({node->left, y - 1});
        if (node->right)
            q.push({node->right, y + 1});
    }
    vector<int> ans;
    for (auto &i : mp)
        for (auto &j : i.second)
            ans.push_back(j);
    return ans;
}
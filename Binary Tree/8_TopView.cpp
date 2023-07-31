#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *&root)
{
    if (!root)
        return {};
    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        TreeNode<int> *node = q.front().first;
        int y = q.front().second;
        if (mp.find(y) == mp.end())
            mp[y] = node->val;
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
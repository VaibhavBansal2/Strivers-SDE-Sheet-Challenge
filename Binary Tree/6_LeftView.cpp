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

vector<int> getLeftView(TreeNode<int> *&root)
{
    if (!root)
        return {};
    queue<TreeNode<int> *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        int n = q.size();
        while (n--)
        {
            TreeNode<int> *node = q.front();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            q.pop();
        }
    }
    return ans;
}
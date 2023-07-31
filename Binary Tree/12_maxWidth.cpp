#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *&root)
{
    if (!root)
        return 0;
    queue<TreeNode<int> *> q;
    q.push(root);
    int ans = 0;
    while (!q.empty())
    {
        int n = q.size();
        ans = max(ans, n);
        while (n--)
        {
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
    }
    return ans;
}
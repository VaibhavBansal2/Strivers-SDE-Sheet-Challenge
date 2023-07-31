/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        bool b = false;
        stack<TreeNode *> st1, st2;
        st1.push(root);
        vector<int> v;
        while (!st1.empty())
        {
            TreeNode *n = st1.top();
            st1.pop();
            v.push_back(n->val);
            if (b)
            {
                if (n->right)
                    st2.push(n->right);
                if (n->left)
                    st2.push(n->left);
            }
            else
            {
                if (n->left)
                    st2.push(n->left);
                if (n->right)
                    st2.push(n->right);
            }
            if (st1.empty())
            {
                swap(st1, st2);
                b ^= 1;
                ans.push_back(v);
                v.clear();
            }
        }
        return ans;
    }
};
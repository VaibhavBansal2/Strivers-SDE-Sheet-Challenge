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
    int ans;
    int rec(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = rec(root->left), r = rec(root->right);
        int a = max(max(l, r) + root->val, root->val);
        ans = max(max(l + r + root->val, a), ans);
        return a;
    }

    int maxPathSum(TreeNode *root)
    {
        ans = -1000;
        rec(root);
        return ans;
    }
};
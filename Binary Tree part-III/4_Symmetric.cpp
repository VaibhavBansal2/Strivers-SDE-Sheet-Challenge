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
    bool check(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
            return true;
        if (root && subRoot)
        {
            bool a = check(root->left, subRoot->right);
            bool b = check(root->right, subRoot->left);
            bool c = (root->val == subRoot->val);
            if (a && b && c)
                return true;
        }
        return false;
    }

public:
    bool isSymmetric(TreeNode *&root)
    {
        return check(root->left, root->right);
    }
};

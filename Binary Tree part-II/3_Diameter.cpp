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
int ans;
int rec(TreeNode<int> *&root)
{
    if (!root)
        return 0;
    int l = rec(root->left), r = rec(root->right);
    ans = max(ans, l + r);
    return max(l, r) + 1;
}
int diameterOfBinaryTree(TreeNode<int> *&root)
{
    ans = 0;
    rec(root);
    return ans;
}
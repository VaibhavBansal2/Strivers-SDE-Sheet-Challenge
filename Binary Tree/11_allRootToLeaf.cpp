void dfs(BinaryTreeNode<int> *root, vector<string> &result, string curr)
{
    if (!root)
        return;
    curr += to_string(root->data) + " ";
    if (!root->left && !root->right)
        result.push_back(curr.substr(0, curr.size() - 1));
    if (root->left)
        dfs(root->left, result, curr);
    if (root->right)
        dfs(root->right, result, curr);
    return;
}

vector<string> allRootToLeaf(BinaryTreeNode<int> *root)
{
    vector<string> result;
    dfs(root, result, "");
    return result;
}
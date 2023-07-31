#include <unordered_map>
/************************************************************

   Following is the TreeNode class structure

   class TreeNode<T>
   {
   public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
   };


 ************************************************************/
TreeNode<int> *construct(vector<int> &inorder, vector<int> &postOrder, unordered_map<int, int> &ump, int l, int r, int &i)
{
    if (l > r)
        return nullptr;
    TreeNode<int> *root = new TreeNode<int>(postOrder[i]);
    int idx = ump[postOrder[i--]];
    root->right = construct(inorder, postOrder, ump, idx + 1, r, i);
    root->left = construct(inorder, postOrder, ump, l, idx - 1, i);
    return root;
}

TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    unordered_map<int, int> ump;
    for (int i = 0; i < inOrder.size(); i++)
        ump[inOrder[i]] = i;
    int i = postOrder.size() - 1;
    return construct(inOrder, postOrder, ump, 0, inOrder.size() - 1, i);
}

#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

bool identicalTrees(BinaryTreeNode<int> *&p, BinaryTreeNode<int> *&q)
{
    if (!p && !q)
        return true;
    if (p && q)
    {
        bool a = identicalTrees(p->left, q->left);
        bool b = identicalTrees(p->right, q->right);
        bool c = (p->data == q->data);
        if (a && b && c)
            return true;
    }
    return false;
}
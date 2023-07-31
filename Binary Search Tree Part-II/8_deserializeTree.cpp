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

string serializeTree(TreeNode<int> *&root)
{
    if (!root)
        return "";
    queue<TreeNode<int> *> q;
    q.push(root);
    string ans = "";
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode<int> *temp = q.front();
            q.pop();
            if (temp)
            {
                q.push(temp->left);
                q.push(temp->right);
                ans += to_string(temp->data);
            }
            else
                ans += "N";
            ans += ",";
        }
    }
    return ans;
}

TreeNode<int> *deserializeTree(string &data)
{
    if (!data.length())
        return NULL;
    int i = 0, n = data.size();
    string s = "";
    while (data[i] != ',')
        s += data[i++];
    TreeNode<int> *root = new TreeNode<int>(stoi(s));
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty() && ++i < n)
    {
        TreeNode<int> *temp = q.front();
        q.pop();
        if (data[i] != 'N')
        {
            s = "";
            while (data[i] != ',')
                s += data[i++];
            temp->left = new TreeNode<int>(stoi(s));
            q.push(temp->left);
        }
        else
            i++;
        if (++i == n)
            return root;
        if (data[i] != 'N')
        {
            s = "";
            while (data[i] != ',')
                s += data[i++];
            temp->right = new TreeNode<int>(stoi(s));
            q.push(temp->right);
        }
        else
            i++;
    }
    return root;
}
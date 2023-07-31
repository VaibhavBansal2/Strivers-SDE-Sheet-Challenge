struct node
{
    node *children[26];
    int count = 0;
};

class Trie
{

public:
    node *root = new node();

    void insert(string &word)
    {
        node *temp = root;
        for (auto &i : word)
        {
            temp->children[i - 'a'] = new node();
            temp = temp->children[i - 'a'];
            temp->count++;
        }
    }

    int prefix(string &word, int &idx)
    {
        if (!root->children[word[0] - 'a'])
            return -1;
        node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->children[word[i] - 'a'] || temp->children[word[i] - 'a']->count != idx)
                return i - 1;
            temp = temp->children[word[i] - 'a'];
            temp->count++;
        }
        return word.size() - 1;
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *obj = new Trie();
    obj->insert(arr[0]);
    int idx;
    for (int i = 1; i < n; i++)
    {
        int val = obj->prefix(arr[i], i);
        if (val == -1)
            return "";
        idx = val;
    }
    return arr[0].substr(0, idx + 1);
}
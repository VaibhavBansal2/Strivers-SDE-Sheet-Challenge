struct node
{
    node *children[26];
};

int countDistinctSubstrings(string &s)
{
    node *root = new node();
    int ans = 0, n = s.size();
    for (int i = 0; i < n; i++)
    {
        node *temp = root;
        for (int j = i; j < n; j++)
        {
            if (!temp->children[s[j] - 'a'])
                temp->children[s[j] - 'a'] = new node(), ans++;
            temp = temp->children[s[j] - 'a'];
        }
    }
    return ans + 1;
}
struct node
{
    node *children[2];
};

int getbit(int &n, int &pos)
{
    return (n >> pos) & 1;
}

inline void setbit(int &n, int &pos)
{
    n |= (1 << pos);
}

class Trie
{
    node *root;

public:
    Trie()
    {
        root = new node();
    }

    void insert(int &n)
    {
        node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = getbit(n, i);
            if (!temp->children[bit])
                temp->children[bit] = new node();
            temp = temp->children[bit];
        }
    }

    int getMax(int &x)
    {
        node *temp = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = getbit(x, i);
            if (temp->children[1 - bit])
            {
                setbit(ans, i);
                temp = temp->children[1 - bit];
            }
            else
                temp = temp->children[bit];
        }
        return ans;
    }
};

int maximumXor(vector<int> &A)
{
    Trie trie;
    for (auto &i : A)
        trie.insert(i);
    int ans = 0;
    for (auto &i : A)
        ans = max(ans, trie.getMax(i));
    return ans;
}
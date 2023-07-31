/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct node
{
    node *children[26];
    bool flag = false;
};

class Trie
{

public:
    node *root = new node();

    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string &word)
    {
        node *temp = root;
        for (auto &i : word)
        {
            if (!temp->children[i - 'a'])
                temp->children[i - 'a'] = new node();
            temp = temp->children[i - 'a'];
        }
        temp->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string &word)
    {
        node *temp = root;
        for (auto &i : word)
        {
            if (!temp->children[i - 'a'])
                return false;
            temp = temp->children[i - 'a'];
        }
        return temp->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string &prefix)
    {
        node *temp = root;
        for (auto &i : prefix)
        {
            if (!temp->children[i - 'a'])
                return false;
            temp = temp->children[i - 'a'];
        }
        return true;
    }
};
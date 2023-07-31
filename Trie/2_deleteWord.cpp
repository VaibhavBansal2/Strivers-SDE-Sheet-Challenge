#include <bits/stdc++.h>

/*class TrieNode {                        //Definition of TrieNode class
public:
    TrieNode * children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }

};*/

TrieNode *solution::deleteWord(TrieNode *root, string word)
{
    for (auto &i : word)
    {
        if (!root->children[i - 'a'])
            return NULL;
        root = root->children[i - 'a'];
    }
    root->isEnd = false;
    return NULL;
}
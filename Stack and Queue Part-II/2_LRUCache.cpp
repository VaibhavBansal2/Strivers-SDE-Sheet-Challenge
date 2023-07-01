#include <bits/stdc++.h>

class LRUCache
{
public:
    unordered_map<int, pair<int, int>> ump;
    queue<int> q;
    int maxSize;

    LRUCache(int &capacity) { maxSize = capacity; }

    int get(int key)
    {
        if (ump.find(key) == ump.end())
            return -1;
        q.push(key);
        ump[key].second++;
        return ump[key].first;
    }

    void put(int key, int value)
    {
        if (ump.find(key) == ump.end() && ump.size() == maxSize)
        {
            while (ump[q.front()].second != 1)
            {
                ump[q.front()].second--;
                q.pop();
            }
            ump.erase(ump.find(q.front()));
            q.pop();
        }
        q.push(key);
        ump[key].first = value;
        ump[key].second++;
    }
};
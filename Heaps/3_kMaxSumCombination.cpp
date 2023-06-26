#include <bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int &k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> maxh;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    set<pair<int, int>> s;
    vector<int> ans;
    maxh.push({a[0] + b[0], {0, 0}});
    while (k--)
    {
        ans.push_back(maxh.top().first);
        int x = maxh.top().second.first, y = maxh.top().second.second;
        maxh.pop();
        if (x + 1 < a.size() && s.find({x + 1, y}) == s.end())
            maxh.push({a[x + 1] + b[y], {x + 1, y}}), s.insert({x + 1, y});
        if (y + 1 < b.size() && s.find({x, y + 1}) == s.end())
            maxh.push({a[x] + b[y + 1], {x, y + 1}}), s.insert({x, y + 1});
    }
    return ans;
}
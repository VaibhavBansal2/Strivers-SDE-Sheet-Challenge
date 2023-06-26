#include <bits/stdc++.h>
vector<int> KMostFrequent(int &n, int &k, vector<int> &arr)
{
    unordered_map<int, int> ump;
    for (auto i : arr)
        ump[i]++;
    unordered_map<int, vector<int>> umv;
    for (auto i : ump)
        umv[i.second].push_back(i.first);
    vector<int> ans;
    for (int i = n; i >= 0 && k > 0; i--)
        for (auto j : umv[i])
            ans.push_back(j), k--;
    sort(ans.begin(), ans.end());
    return ans;
}
#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> ans;
    for (auto &i : kArrays)
        for (auto &j : i)
            ans.push_back(j);
    sort(ans.begin(), ans.end());
    return ans;
}
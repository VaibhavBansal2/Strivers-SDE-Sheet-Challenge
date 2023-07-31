#include <bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int &k)
{
    unordered_map<int, int> ump;
    for (int i = 0; i < k; i++)
        ump[arr[i]]++;
    vector<int> ans;
    for (int i = k; i < arr.size(); i++)
    {
        ans.push_back(ump.size());
        if (!--ump[arr[i - k]])
            ump.erase(ump.find(arr[i - k]));
        ump[arr[i]]++;
    }
    ans.push_back(ump.size());
    return ans;
}
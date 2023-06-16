#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int &x)
{
    int a = 0, ans = 0;
    unordered_map<int, int> ump;
    for (auto &i : arr)
    {
        a ^= i;
        if (a == x)
            ans++;
        if (ump.find(a ^ x) != ump.end())
            ans += ump[a ^ x];
        ump[a]++;
    }
    return ans;
}
#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> &arr)
{
    unordered_map<int, int> ump;
    int sum = 0, n = arr.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (!sum)
            ans = i + 1;
        else if (ump.find(sum) != ump.end())
            ans = max(ans, i - ump[sum]);
        else
            ump[sum] = i;
    }
    return ans;
}
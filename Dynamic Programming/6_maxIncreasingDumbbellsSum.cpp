#include <bits/stdc++.h>
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    vector<int> dp = rack;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (rack[i] > rack[j])
                dp[i] = max(dp[i], dp[j] + rack[i]);
    return *max_element(dp.begin(), dp.end());
}
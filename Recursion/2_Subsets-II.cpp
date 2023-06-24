#include <bits/stdc++.h>

void rec(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int &n, int idx = 0)
{
    ans.push_back(temp);
    for (int i = idx; i < n; i++)
    {
        if (i != idx && nums[i] == nums[i - 1])
            continue;
        temp.push_back(nums[i]);
        rec(nums, temp, ans, n, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int &n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<int> temp;
    vector<vector<int>> ans;
    rec(arr, temp, ans, n);
    return ans;
}
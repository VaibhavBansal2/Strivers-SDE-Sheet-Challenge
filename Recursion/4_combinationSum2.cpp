#include <bits/stdc++.h>

void rec(vector<int> &nums, vector<int> &temp, int &n, vector<vector<int>> &ans, int target, int idx = 0)
{
    if (!target)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (i != idx && nums[i] == nums[i - 1])
            continue;
        if (nums[i] > target)
            break;
        temp.push_back(nums[i]);
        rec(nums, temp, n, ans, target - nums[i], i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int &n, int &target)
{
    sort(arr.begin(), arr.end());
    vector<int> temp;
    vector<vector<int>> ans;
    rec(arr, temp, n, ans, target);
    return ans;
}
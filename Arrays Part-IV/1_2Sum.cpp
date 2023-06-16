// CodeStudio

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int &s)
{
    unordered_map<int, int> ump;
    for (auto &i : arr)
        ump[i]++;
    int l = 0, r = arr.size() - 1;
    vector<vector<int>> ans;
    for (auto &i : arr)
        if (i <= s - i && ump.find(s - i) != ump.end())
        {
            ump[i]--;
            for (int j = 0; j < ump[s - i]; j++)
                ans.push_back({i, s - i});
            ump[i++];
        }
    sort(ans.begin(), ans.end());
    return ans;
}


// Leetcode

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        int s = 0, e = n - 1;
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
            vp.push_back({nums[i], i});
        sort(vp.begin(), vp.end());
        while (s < e)
        {
            if (vp[s].first + vp[e].first == target)
                break;
            if (vp[s].first + vp[e].first > target)
                e--;
            else
                s++;
        }
        return {vp[s].second, vp[e].second};
    }
};
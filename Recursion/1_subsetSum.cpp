#include <bits/stdc++.h>

void rec(vector<int> &num, vector<int> &ans, int sum = 0, int i = 0)
{
    if (i == num.size())
    {
        ans.push_back(sum);
        return;
    }
    rec(num, ans, sum, i + 1);
    rec(num, ans, sum + num[i], i + 1);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    rec(num, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
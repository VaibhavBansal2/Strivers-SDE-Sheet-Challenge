#include <bits/stdc++.h>

vector<vector<int>> ans;
void rec(vector<int> &v, vector<int> &temp, int i = 0)
{
    if (i == v.size())
    {
        ans.push_back(temp);
        return;
    }
    rec(v, temp, i + 1);
    temp.push_back(v[i]);
    rec(v, temp, i + 1);
    temp.pop_back();
}

vector<vector<int>> pwset(vector<int> &v)
{
    vector<int> temp;
    rec(v, temp);
    return ans;
}
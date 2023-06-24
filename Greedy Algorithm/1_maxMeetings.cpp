#include <bits/stdc++.h>

bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
    if (a.first.first != b.first.first)
        return a.first.first < b.first.first;
    if (a.second != b.second)
        return a.second < b.second;
    return a.first.second < b.first.second;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<pair<int, int>, int>> vp;
    for (int i = 0; i < n; i++)
        vp.push_back({{end[i], start[i]}, i + 1});
    sort(vp.begin(), vp.end(), cmp);
    int e = vp[0].first.first;
    vector<int> ans = {vp[0].second};
    for (int i = 1; i < n; i++)
        if (vp[i].first.second > e)
            ans.push_back(vp[i].second), e = vp[i].first.first;
    return ans;
}
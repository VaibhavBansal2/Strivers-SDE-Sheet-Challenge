#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
        vp.push_back({end[i], start[i]});
    sort(vp.begin(), vp.end());
    int ans = 1, e = vp[0].first;
    for (int i = 1; i < n; i++)
        if (vp[i].second >= e)
            ans++, e = vp[i].first;
    return ans;
}
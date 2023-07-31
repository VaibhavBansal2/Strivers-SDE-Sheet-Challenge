#include <bits/stdc++.h>

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[1] != b[1])
        return a[1] > b[1];
    return a[0] < b[0];
}

int find(vector<int> &parent, int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), cmp);
    int mx = 0;
    for (auto &i : jobs)
        mx = max(mx, i[0]);
    vector<int> parent(mx + 1, 0);
    for (int i = 1; i <= mx; i++)
        parent[i] = i;
    int ans = 0;
    for (auto &i : jobs)
    {
        int pos = find(parent, i[0]);
        if (pos)
        {
            ans += i[1];
            parent[pos] = find(parent, pos - 1);
        }
    }
    return ans;
}
#include <bits/stdc++.h>

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return (double)a.second / a.first > (double)b.second / b.first;
}

double maximumValue(vector<pair<int, int>> &items, int &n, int &w)
{
    sort(items.begin(), items.end(), cmp);
    double ans = 0;
    for (auto &i : items)
        if (i.first <= w)
            ans += i.second, w -= i.first;
        else
        {
            ans += ((double)i.second / i.first) * w;
            break;
        }
    return ans;
}
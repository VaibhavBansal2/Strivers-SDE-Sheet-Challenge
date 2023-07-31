#include <bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n)
{
    int mn = 1, mx = 1, ans = INT_MIN;
    for (auto i : arr)
        if (i)
        {
            int curr_mx = max(i, max(i * mx, i * mn));
            mn = min(i, min(i * mx, i * mn));
            mx = curr_mx;
            ans = max(ans, mx);
        }
        else
        {
            mx = mn = 1;
            ans = max(ans, 0);
        }
    return ans;
}
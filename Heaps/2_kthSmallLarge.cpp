#include <bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int &n, int &k)
{
    vector<int> ans;
    nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
    ans.push_back(arr[k - 1]);
    nth_element(arr.begin(), arr.begin() + n - k, arr.end());
    ans.push_back(arr[n - k]);
    return ans;
}
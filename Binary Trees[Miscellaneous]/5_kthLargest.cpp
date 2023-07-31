#include <bits/stdc++.h>
int kthLargest(vector<int> &nums, int &size, int &k)
{
    priority_queue<int, vector<int>> maxh;
    for (auto &i : nums)
        maxh.push(i);
    while (--k)
        maxh.pop();
    return maxh.top();
}
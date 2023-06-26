#include <bits/stdc++.h>
vector<int> minHeap(int n, vector<vector<int>> &q)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> ans;
    for (auto &i : q)
        if (i[0])
            ans.push_back(minh.top()), minh.pop();
        else
            minh.push(i[1]);
    return ans;
}
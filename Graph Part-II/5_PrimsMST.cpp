#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int &n, int &m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int, int>> adj[n + 1];
    for (auto &i : g)
        adj[i.first.first].push_back({i.first.second, i.second}), adj[i.first.second].push_back({i.first.first, i.second});
    vector<bool> vis(n + 1, 0);
    vector<pair<pair<int, int>, int>> ans;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
    minh.push({0, 1, -1});
    while (!minh.empty())
    {
        vector<int> top = minh.top();
        minh.pop();
        int w = top[0], node = top[1], parent = top[2];
        if (vis[node])
            continue;
        vis[node] = 1;
        if (parent != -1)
            ans.push_back({{parent, node}, w});
        for (auto &i : adj[node])
            if (!vis[i.first])
                minh.push({i.second, i.first, node});
    }
    return ans;
}
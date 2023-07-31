#include <bits/stdc++.h>
void dfs(vector<int> adj[], vector<bool> &vis, vector<int> &ans, int node)
{
    vis[node] = 1;
    for (auto &i : adj[node])
        if (!vis[i])
            dfs(adj, vis, ans, i);
    ans.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int &v, int &e)
{
    vector<int> adj[v];
    for (auto &i : edges)
        adj[i[0]].push_back(i[1]);
    vector<bool> vis(v, 0);
    vector<int> ans;
    for (int i = 0; i < v; i++)
        if (!vis[i])
            dfs(adj, vis, ans, i);
    reverse(ans.begin(), ans.end());
    return ans;
}
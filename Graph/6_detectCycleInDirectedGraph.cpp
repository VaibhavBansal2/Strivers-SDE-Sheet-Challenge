bool isCycle(int &src, vector<int> adjl[], vector<bool> &vis, vector<bool> &rec)
{
    rec[src] = true, vis[src] = true;
    for (auto i : adjl[src])
        if ((!vis[i] && isCycle(i, adjl, vis, rec)) || rec[i])
            return true;
    rec[src] = false;
    return false;
}

int detectCycleInDirectedGraph(int &n, vector<pair<int, int>> &edges)
{
    vector<int> adj[n];
    vector<bool> vis(n, 0), rec(n, 0);
    for (auto &i : edges)
        adj[i.first - 1].push_back(i.second - 1);
    for (int i = 0; i < n; i++)
        if (!vis[i] && isCycle(i, adj, vis, rec))
            return 1;
    return 0;
}
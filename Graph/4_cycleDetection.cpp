bool isCycle(int &src, vector<int> adjl[], vector<bool> &vis, int parent)
{
    vis[src] = 1;
    for (auto i : adjl[src])
        if (i != parent && (vis[i] || isCycle(i, adjl, vis, src)))
            return true;
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<int> adj[n];
    for (auto &i : edges)
        adj[i[0] - 1].push_back(i[1] - 1), adj[i[1] - 1].push_back(i[0] - 1);
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++)
        if (!vis[i] && isCycle(i, adj, vis, -1))
            return "Yes";
    return "No";
}
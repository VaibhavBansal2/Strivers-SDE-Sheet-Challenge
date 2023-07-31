bool bipartite(vector<int> &color, vector<int> adj[], int &src, bool col)
{
    if (color[src] != -1)
        return (color[src] != col) ? false : true;
    color[src] = col;
    for (auto i : adj[src])
        if (!bipartite(color, adj, i, col ^ 1))
            return false;
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (edges[i][j])
                adj[i].push_back(j);
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
        if (color[i] == -1 && !bipartite(color, adj, i, 0))
            return false;
    return true;
}
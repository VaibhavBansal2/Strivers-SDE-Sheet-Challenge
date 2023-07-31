void dfs(vector<int> adj[], vector<bool> &vis, vector<int> &v, int &node)
{
    vis[node] = 1;
    for (auto &i : adj[node])
        if (!vis[i])
            dfs(adj, vis, v, i);
    v.push_back(node);
}

vector<vector<int>> stronglyConnectedComponents(int &n, vector<vector<int>> &edges)
{
    vector<int> adj[n], trans[n];
    for (auto &i : edges)
        adj[i[0]].push_back(i[1]), trans[i[1]].push_back(i[0]);
    vector<bool> vis(n, 0);
    vector<int> topo;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(adj, vis, topo, i);
    reverse(topo.begin(), topo.end());
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    vector<vector<int>> ans;
    for (auto &i : topo)
        if (!vis[i])
        {
            vector<int> temp;
            dfs(trans, vis, temp, i);
            ans.push_back(temp);
        }
    return ans;
}
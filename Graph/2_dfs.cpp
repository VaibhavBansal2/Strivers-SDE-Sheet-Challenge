void dfs(vector<int> adj[], int node, vector<bool> &vis, vector<int> &ans)
{
    vis[node] = true;
    ans.push_back(node);
    for (auto i : adj[node])
        if (!vis[i])
            dfs(adj, i, vis, ans);
}

vector<vector<int>> depthFirstSearch(int &V, int &E, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for (auto &i : edges)
        adj[i[0]].push_back(i[1]), adj[i[1]].push_back(i[0]);
    vector<bool> vis(V, 0);
    vector<vector<int>> ans;
    for (int i = 0; i < V; i++)
        if (!vis[i])
        {
            vector<int> temp;
            dfs(adj, i, vis, temp);
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
    return ans;
}
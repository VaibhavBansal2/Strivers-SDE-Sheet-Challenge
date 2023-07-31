#include <queue>
string cycleDetection(vector<vector<int>> &edges, int &n, int &m)
{
    vector<int> adj[n];
    for (auto &i : edges)
        adj[i[0] - 1].push_back(i[1] - 1), adj[i[1] - 1].push_back(i[0] - 1);
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            queue<pair<int, int>> q;
            q.push({i, -1});
            while (!q.empty())
            {
                int src = q.front().first, parent = q.front().second;
                q.pop();
                for (auto j : adj[src])
                    if (j != parent)
                        if (vis[j])
                            return "Yes";
                        else
                            vis[j] = 1, q.push({j, src});
            }
        }
    return "No";
}
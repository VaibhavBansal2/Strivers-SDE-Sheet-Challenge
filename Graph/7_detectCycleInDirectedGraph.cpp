#include <queue>
int detectCycleInDirectedGraph(int &n, vector<pair<int, int>> &edges)
{
    vector<int> adj[n];
    vector<bool> vis(n, 0);
    for (auto &i : edges)
        adj[i.first - 1].push_back(i.second - 1);
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            vector<bool> rec(n, 0);
            rec[i] = 1, vis[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int src = q.front();
                q.pop();
                for (auto &j : adj[src])
                {
                    if (rec[j])
                        return 1;
                    rec[j] = 1;
                    if (!vis[j])
                    {
                        vis[j] = 1;
                        q.push(j);
                    }
                }
            }
        }
    return 0;
}
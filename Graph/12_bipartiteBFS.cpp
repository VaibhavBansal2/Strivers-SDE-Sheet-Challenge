#include <queue>
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (edges[i][j])
                adj[i].push_back(j);
    vector<int> color(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!color[i])
        {
            color[i] = 1;
            q.push(i);
            while (!q.empty())
            {
                int src = q.front();
                q.pop();
                for (auto &j : adj[src])
                    if (!color[j])
                        color[j] = -color[src], q.push(j);
                    else if (color[j] == color[src])
                        return false;
            }
        }
    return true;
}
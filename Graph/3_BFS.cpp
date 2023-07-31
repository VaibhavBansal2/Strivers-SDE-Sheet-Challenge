#include <bits/stdc++.h>
vector<int> BFS(int &vertex, vector<pair<int, int>> &edges)
{
    vector<int> adj[vertex];
    for (auto &i : edges)
        if (i.first > i.second)
            swap(i.first, i.second);
    sort(edges.begin(), edges.end());
    for (auto &i : edges)
        adj[i.first].push_back(i.second), adj[i.second].push_back(i.first);
    vector<bool> vis(vertex, 0);
    vector<int> ans;
    for (int idx = 0; idx < vertex; idx++)
        if (!vis[idx])
        {
            queue<int> q;
            q.push(idx);
            vis[idx] = 1;
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                for (int i = 0; i < adj[temp].size(); i++)
                    if (!vis[adj[temp][i]])
                    {
                        q.push(adj[temp][i]);
                        vis[adj[temp][i]] = 1;
                    }
                ans.push_back(temp);
            }
        }
    return ans;
}
#include <bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int &v, int &e)
{
    vector<int> adj[v], indeg(v, 0);
    for (auto &i : edges)
        adj[i[0]].push_back(i[1]), indeg[i[1]]++;
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (!indeg[i])
            q.push(i);
    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for (auto i : adj[node])
            if (!--indeg[i])
                q.push(i);
    }
    return ans;
}
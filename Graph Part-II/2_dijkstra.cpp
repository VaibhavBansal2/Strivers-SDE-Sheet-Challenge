#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int &vertices, int &edges, int source)
{
    vector<pair<int, int>> adj[vertices];
    for (auto &i : vec)
        adj[i[0]].push_back({i[2], i[1]}), adj[i[1]].push_back({i[2], i[0]});
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
    minh.push({0, source});
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    while (!minh.empty())
    {
        int src = minh.top().second, d = minh.top().first;
        minh.pop();
        for (auto &i : adj[src])
        {
            int node = i.second, w = i.first;
            if (d + w < dist[node])
                dist[node] = d + w, minh.push({d + w, node});
        }
    }
    return dist;
}
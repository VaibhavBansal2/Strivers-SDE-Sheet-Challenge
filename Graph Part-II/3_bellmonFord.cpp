#include <bits/stdc++.h>
int bellmonFord(int &n, int &m, int &src, int &dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
        for (auto &j : edges)
            if (dist[j[0]] != 1e9 && dist[j[0]] + j[2] < dist[j[1]])
                dist[j[1]] = dist[j[0]] + j[2];
    return dist[dest];
}
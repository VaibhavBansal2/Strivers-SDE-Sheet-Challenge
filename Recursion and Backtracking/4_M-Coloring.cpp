#include <bits/stdc++.h>

bool solve(vector<int> adj[], vector<int> &col, int &m, int &n, int i = 0)
{
    if (i == n)
        return true;
    for (int k = 1; k <= m; k++)
    {
        bool can = true;
        for (auto &j : adj[i])
            if (col[j] == k)
            {
                can = false;
                break;
            }
        if (can)
        {
            col[i] = k;
            if (solve(adj, col, m, n, i + 1))
                return true;
            col[i] = -1;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int &m)
{
    int n = mat.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j])
                adj[i].push_back(j);
    vector<int> col(n, -1);
    if (solve(adj, col, m, n))
        return "YES";
    return "NO";
}
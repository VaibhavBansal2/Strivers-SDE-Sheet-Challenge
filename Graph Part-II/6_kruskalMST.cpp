#include <bits/stdc++.h>

class DSU
{
    vector<int> size, parent;

public:
    DSU(int &n)
    {
        parent.resize(n + 1), size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int &i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int &x, int &y)
    {
        if (size[x] < size[y])
            parent[x] = y, size[y] += size[x];
        else
            parent[y] = x, size[x] += size[y];
    }
};

int kruskalMST(int &n, int &m, vector<vector<int>> &graph)
{
    sort(graph.begin(), graph.end(), [&](vector<int> &a, vector<int> &b)
         { return a[2] <= b[2]; });
    int ans = 0;
    DSU dsu(n);
    for (auto &i : graph)
    {
        int x = dsu.find(i[0]), y = dsu.find(i[1]);
        if (x != y)
        {
            dsu.unite(x, y);
            ans += i[2];
        }
    }
    return ans;
}
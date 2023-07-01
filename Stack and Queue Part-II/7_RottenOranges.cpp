#include <bits/stdc++.h>

int minTimeToRot(vector<vector<int>> &grid, int &n, int &m)
{
    swap(n, m);
    queue<vector<int>> q;
    int cntFresh = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
                q.push({i, j, 0});
            if (grid[i][j] == 1)
                cntFresh++;
        }
    int ans = 0;
    vector<int> r{1, 0, -1, 0}, c{0, 1, 0, -1};
    while (!q.empty())
    {
        int x = q.front()[0];
        int y = q.front()[1];
        int z = q.front()[2];
        q.pop();
        ans = max(ans, z);
        for (int i = 0; i < 4; i++)
        {
            x = x + r[i];
            y = y + c[i];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
            {
                grid[x][y] = 2;
                q.push({x, y, z + 1});
                cntFresh--;
            }
            x = x - r[i];
            y = y - c[i];
        }
    }
    if (cntFresh)
        return -1;
    return ans;
}
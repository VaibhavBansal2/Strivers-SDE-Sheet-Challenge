#include <bits/stdc++.h>

vector<vector<int>> ans;

void rec(vector<vector<int>> &maze, int &n, vector<vector<int>> &vis, int x = 0, int y = 0)
{
    if (x < 0 || y < 0 || x == n || y == n || !maze[x][y] || vis[x][y])
        return;
    if (x == n - 1 && y == n - 1)
    {
        vis[x][y] = 1;
        vector<int> temp;
        for (auto &i : vis)
            for (auto &j : i)
                temp.push_back(j);
        ans.push_back(temp);
        vis[x][y] = 0;
        return;
    }
    vis[x][y] = 1;
    rec(maze, n, vis, x + 1, y);
    rec(maze, n, vis, x, y + 1);
    rec(maze, n, vis, x - 1, y);
    rec(maze, n, vis, x, y - 1);
    vis[x][y] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> vis(n, vector<int>(n, 0));
    rec(maze, n, vis);
    return ans;
}
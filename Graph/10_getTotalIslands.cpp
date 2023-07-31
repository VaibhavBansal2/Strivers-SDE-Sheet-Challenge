void dfs(int **grid, int &m, int &n, int i, int j)
{
    if (i == -1 || i == m || j == -1 || j == n || !grid[i][j])
        return;
    grid[i][j] = 0;
    dfs(grid, m, n, i + 1, j);
    dfs(grid, m, n, i, j + 1);
    dfs(grid, m, n, i - 1, j);
    dfs(grid, m, n, i, j - 1);
    dfs(grid, m, n, i + 1, j - 1);
    dfs(grid, m, n, i - 1, j - 1);
    dfs(grid, m, n, i + 1, j + 1);
    dfs(grid, m, n, i - 1, j + 1);
}

int getTotalIslands(int **arr, int n, int m)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j])
                dfs(arr, n, m, i, j), ans++;
    return ans;
}
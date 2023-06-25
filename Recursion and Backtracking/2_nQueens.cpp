#include <bits/stdc++.h>
unordered_map<int, bool> row, ud, ld;
vector<vector<int>> ans;
void backtrack(int &n, vector<int> &v, int c = 0)
{
    if (c == n)
    {
        ans.push_back(v);
        return;
    }
    for (int r = 0; r < n; r++)
        if (!(row[r] || ld[r + c] || ud[n + c - r - 1]))
        {
            v[(c * n) + r] = 1;
            row[r] = 1;
            ld[r + c] = 1;
            ud[n + c - r - 1] = 1;
            backtrack(n, v, c + 1);
            v[(c * n) + r] = 0;
            row[r] = 0;
            ld[r + c] = 0;
            ud[n + c - r - 1] = 0;
        }
}

vector<vector<int>> solveNQueens(int &n)
{
    vector<int> v(n * n, 0);
    backtrack(n, v);
    return ans;
}
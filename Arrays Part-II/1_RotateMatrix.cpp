// CodeStudio

#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int &n, int &m)
{
    for (int k = 0; k < (min(n,m) >> 1); k++)
    {
        int temp = mat[k][k];
        for (int i = k; i < n - k - 1; i++)
            mat[i][k] = mat[i + 1][k];
        for (int j = k; j < m - k - 1; j++)
            mat[n - k - 1][j] = mat[n - k - 1][j + 1];
        for (int i = n - k - 1; i > k; i--)
            mat[i][m - k - 1] = mat[i - 1][m - k - 1];
        for (int j = m - k - 1; j > k; j--)
            mat[k][j] = mat[k][j - 1];
        mat[k][k + 1] = temp;
    }
}

// Leetcode

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n >> 1; i++)
            for (int j = i; j < n - i - 1; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
    }
};
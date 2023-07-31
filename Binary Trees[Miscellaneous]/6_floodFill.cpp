int m, n, col, newcol;
vector<vector<int>> matrix;
void func(int x, int y)
{
    if (x >= 0 && y >= 0 && x < m && y < n && matrix[x][y] == col)
    {
        matrix[x][y] = newcol;
        func(x + 1, y);
        func(x - 1, y);
        func(x, y + 1);
        func(x, y - 1);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int &sr, int &sc, int &newColor)
{
    col = image[sr][sc], m = image.size(), n = image[0].size(), newcol = newColor, matrix = image;
    if (col != newcol)
        func(sr, sc);
    return matrix;
}
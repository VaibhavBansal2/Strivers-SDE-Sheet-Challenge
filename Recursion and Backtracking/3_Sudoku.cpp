class Solution
{
public:
    bool backtrack(vector<vector<char>> &board, vector<vector<bool>> &r, vector<vector<bool>> &c, vector<vector<bool>> &b)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                {
                    for (int k = 0; k < 9; k++)
                        if (!(r[i][k] || c[j][k] || b[((i / 3) * 3) + (j / 3)][k]))
                        {
                            board[i][j] = k + '0' + 1;
                            r[i][k] = 1;
                            c[j][k] = 1;
                            b[((i / 3) * 3) + (j / 3)][k] = 1;
                            if (backtrack(board, r, c, b))
                                return true;
                            board[i][j] = '.';
                            r[i][k] = 0;
                            c[j][k] = 0;
                            b[((i / 3) * 3) + (j / 3)][k] = 0;
                        }
                    return false;
                }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> r(9, vector<bool>(9, 0)), c(9, vector<bool>(9, 0)), b(9, vector<bool>(9, 0));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.')
                {
                    r[i][board[i][j] - '0' - 1] = 1;
                    c[j][board[i][j] - '0' - 1] = 1;
                    b[((i / 3) * 3) + (j / 3)][board[i][j] - '0' - 1] = 1;
                }
        backtrack(board, r, c, b);
    }
};
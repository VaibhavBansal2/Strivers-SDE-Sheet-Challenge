int rec(vector<int> &price, vector<vector<int>> &dp, int n, int i)
{
    if (i < 0 || !n)
        return 0;
    if (dp[n][i] != -1)
        return dp[n][i];
    int t = (n >= i + 1) ? rec(price, dp, n - (i + 1), i) + price[i] : 0;
    int nt = rec(price, dp, n, i - 1);
    return dp[n][i] = max(t, nt);
}

int cutRod(vector<int> &price, int &n)
{
    int len = price.size();
    vector<vector<int>> dp(n + 1, vector<int>(len, -1));
    return rec(price, dp, n, len - 1);
}
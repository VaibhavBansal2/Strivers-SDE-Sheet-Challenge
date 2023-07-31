#include <bits/stdc++.h>
int palindromePartitioning(string &str)
{
    int n = str.size();
    vector<vector<bool>> palindrome(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
        palindrome[i][i] = 1;
    for (int len = 2; len <= n; len++)
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if (str[i] == str[j] && (len == 2 || palindrome[i + 1][j - 1]))
                palindrome[i][j] = true;
        }
    vector<int> dp(n, n);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
        if (palindrome[0][i])
            dp[i] = 0;
        else
            for (int j = i; j >= 1; j--)
                if (palindrome[j][i])
                    if (dp[j - 1] + 1 < dp[i])
                        dp[i] = dp[j - 1] + 1;
    return dp[n - 1];
}
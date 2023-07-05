#include <bits/stdc++.h>

bool isPalindrome(string &s, vector<vector<int>> &dp, int start, int end)
{
    while (start < end)
    {
        if (dp[start][end] != -1)
            return dp[start][end];
        if (s[start] != s[end])
            return dp[start][end] = 0;
        return dp[start][end] = isPalindrome(s, dp, start + 1, end - 1);
    }
    return dp[start][end] = 1;
}

string longestPalinSubstring(string &s)
{
    int n = s.length(), len = 1;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    string ans = "";
    ans += s[0];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (isPalindrome(s, dp, i, j) && j - i + 1 > len)
                ans = s.substr(i, j - i + 1), len = j - i + 1;
    return ans;
}
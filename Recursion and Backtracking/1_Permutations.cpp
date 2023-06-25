#include <bits/stdc++.h>
vector<string> ans;
void rec(string &s, int &n, int i = 0)
{
    if (i == n)
    {
        ans.push_back(s);
        return;
    }
    for (int j = i; j < n; j++)
    {
        swap(s[i], s[j]);
        rec(s, n, i + 1);
        swap(s[i], s[j]);
    }
}

vector<string> findPermutations(string &s)
{
    int n = s.size();
    rec(s, n);
    return ans;
}
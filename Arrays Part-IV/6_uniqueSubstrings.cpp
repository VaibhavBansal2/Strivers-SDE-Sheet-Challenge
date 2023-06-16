#include <bits/stdc++.h>
int uniqueSubstrings(string &s)
{
    unordered_set<char> us;
    int n = s.size(), l = 0, r = 0, ans = 0;
    while (r < n)
    {
        if (us.find(s[r]) == us.end())
            us.insert(s[r++]);
        else
        {
            us.erase(us.find(s[l]));
            ans = max(ans, r - l++);
        }
    }
    ans = max(ans, r - l);
    return ans;
}
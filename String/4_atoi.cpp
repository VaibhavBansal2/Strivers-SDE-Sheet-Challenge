#include <bits/stdc++.h>
int atoi(string &str)
{
    if (!str.size())
        return 0;
    bool neg = (str[0] == '-');
    string s = "";
    for (auto &i : str)
        if (i >= '0' && i <= '9')
            s.push_back(i);
    int ans = stoi(s);
    if (neg)
        ans = -ans;
    return ans;
}
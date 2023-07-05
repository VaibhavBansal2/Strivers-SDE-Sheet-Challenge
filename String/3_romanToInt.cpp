#include <bits/stdc++.h>
int romanToInt(string &s)
{
    int i = 0, ans = 0, n = s.length();
    while (i < n && s[i] == 'M')
    {
        ans += 1000;
        i++;
    }
    if (i + 1 < n && s[i] == 'C' && s[i + 1] == 'M')
    {
        ans += 900;
        i += 2;
    }
    else if (i < n && s[i] == 'D')
    {
        ans += 500;
        i++;
    }
    else if (i + 1 < n && s[i] == 'C' && s[i + 1] == 'D')
    {
        ans += 400;
        i += 2;
    }
    while (i < n && s[i] == 'C')
    {
        ans += 100;
        i++;
    }
    if (i + 1 < n && s[i] == 'X' && s[i + 1] == 'C')
    {
        ans += 90;
        i += 2;
    }
    else if (i < n && s[i] == 'L')
    {
        ans += 50;
        i++;
    }
    else if (i + 1 < n && s[i] == 'X' && s[i + 1] == 'L')
    {
        ans += 40;
        i += 2;
    }
    while (i < n && s[i] == 'X')
    {
        ans += 10;
        i++;
    }
    if (i + 1 < n && s[i] == 'I' && s[i + 1] == 'X')
    {
        ans += 9;
        i += 2;
    }
    else if (i < n && s[i] == 'V')
    {
        ans += 5;
        i++;
    }
    else if (i + 1 < n && s[i] == 'I' && s[i + 1] == 'V')
    {
        ans += 4;
        i += 2;
    }
    while (i < n && s[i] == 'I')
    {
        ans += 1;
        i++;
    }
    return ans;
}
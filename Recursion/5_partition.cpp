#include <bits/stdc++.h>

bool isPalindrome(string &s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
        if (s[i++] != s[j--])
            return false;
    return true;
}

vector<vector<string>> ans;
void rec(string &s, vector<string> &temp, string &str, int i = 0)
{
    if (i == s.size())
    {
        if (str == "")
            ans.push_back(temp);
        return;
    }
    str += s[i];
    rec(s, temp, str, i + 1);
    if (isPalindrome(str))
    {
        temp.push_back(str);
        string empty = "";
        rec(s, temp, empty, i + 1);
        temp.pop_back();
    }
    str.pop_back();
}

vector<vector<string>> partition(string &s)
{
    vector<string> temp;
    string str = "";
    rec(s, temp, str);
    return ans;
}
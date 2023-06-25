#include <bits/stdc++.h>

void rec(unordered_set<string> &us, vector<string> &ans, string &s, string &temp, string &str, int i = 0)
{
    if (i == s.size())
    {
        if (str == "")
            ans.push_back(temp);
        return;
    }
    str += s[i];
    rec(us, ans, s, temp, str, i + 1);
    if (us.find(str) != us.end())
    {
        string tmp = temp, emp = "";
        temp += str + " ";
        rec(us, ans, s, temp, emp, i + 1);
        temp = tmp;
    }
    str.pop_back();
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_set<string> us;
    vector<string> ans;
    for (auto &i : dictionary)
        us.insert(i);
    string temp, str;
    rec(us, ans, s, temp, str);
    return ans;
}
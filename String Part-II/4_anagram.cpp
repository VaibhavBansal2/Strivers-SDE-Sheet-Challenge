#include <bits/stdc++.h>
bool areAnagram(string &str1, string &str2)
{
    unordered_map<char, int> ump;
    for (auto &i : str1)
        ump[i]++;
    for (auto &i : str2)
        if (ump.find(i) == ump.end())
            return false;
        else if (!--ump[i])
            ump.erase(ump.find(i));
    return ump.empty();
}
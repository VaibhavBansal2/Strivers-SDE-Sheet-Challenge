vector<int> stringMatch(string text, string pattern)
{
    int n = text.size(), m = pattern.size();
    vector<int> ans;
    for (int i = 0; i <= n - m; i++)
    {
        bool match = true;

        for (int j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
            {
                match = false;
                break;
            }
        if (match)
            ans.push_back(i + 1);
    }
    return ans;
}
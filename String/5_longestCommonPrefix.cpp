string longestCommonPrefix(vector<string> &arr, int n)
{
    int mn = 1000;
    string str = "";
    for (int i = 0; i < arr.size(); i++)
        if (arr[i].size() < mn)
            mn = arr[i].size();
    for (int i = 0; i < mn; i++)
    {
        for (int j = 0; j + 1 < arr.size(); j++)
            if (arr[j][i] != arr[j + 1][i])
                return str;
        str += arr[0][i];
    }
    return str;
}
vector<int> search(string s, string pattern)
{
    int n = s.size(), m = pattern.size();
    int l = 0, r = 0;
    string nStr = pattern + "#" + s;
    int k = nStr.length();
    vector<int> ans;
    int zarr[k];
    zarr[0] = 0;
    for (int i = 1; i < k; i++)
    {
        if (i > r)
        {
            l = i;
            r = i;
            while (r < k && nStr[r - l] == nStr[r])
                r++;
            zarr[i] = (r--) - l;
            if (zarr[i] == m)
                ans.push_back(i + 1 - m - 1);
        }
        else
        {
            int pos = i - l;
            if (zarr[pos] < r - i + 1)
            {
                zarr[i] = zarr[pos];
                if (zarr[i] == m)
                    ans.push_back(i + 1 - m - 1);
            }
            else
            {
                l = i;
                while (r < k && nStr[r - l] == nStr[r])
                    r++;
                zarr[i] = (r--) - l;
                if (zarr[i] == m)
                    ans.push_back(i + 1 - m - 1);
            }
        }
    }
    return ans;
}
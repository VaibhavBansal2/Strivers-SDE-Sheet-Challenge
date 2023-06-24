int calculateMinPatforms(int at[], int dt[], int &n)
{
    vector<int> arr(2400, 0), dep(2400, 0);
    for (int i = 0; i < n; i++)
        arr[at[i]]++, dep[dt[i]]++;
    int ans = 1, count = 0;
    for (int i = 0; i < 2400; i++)
    {
        count += arr[i];
        ans = max(ans, count);
        count -= dep[i];
    }
    return ans;
}
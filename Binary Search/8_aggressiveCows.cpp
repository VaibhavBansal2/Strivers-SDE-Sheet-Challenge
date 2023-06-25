bool isFeasible(vector<int> &v, int &k, int &mid)
{
    int p = 0, count = 1;
    for (int i = 0; i < v.size(); i++)
        if (v[i] - v[p] >= mid)
        {
            count++;
            p = i;
            if (count == k)
                return true;
        }
    return false;
}

int aggressiveCows(vector<int> &v, int &k)
{
    sort(v.begin(), v.end());
    int low = 1, high = v[v.size() - 1], ans = -1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (isFeasible(v, k, mid))
        {
            low = mid + 1;
            ans = max(ans, mid);
        }
        else
            high = mid;
    }
    return ans;
}
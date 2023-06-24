string kthPermutation(int &n, int &k)
{
    int f = 1;
    vector<int> v;
    for (int i = 1; i < n; i++)
        f *= i, v.push_back(i);
    v.push_back(n), k--;
    string ans = "";
    while (1)
    {
        int idx = k / f;
        ans += v[idx] + '0';
        v.erase(v.begin() + idx);
        if (!--n)
            break;
        k %= f;
        f /= n;
    }
    return ans;
}
int NthRoot(int &n, int &m)
{
    int l = 1, r = m;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int p = pow(mid, n);
        if (p == m)
            return mid;
        else if (p > m || p < 0)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
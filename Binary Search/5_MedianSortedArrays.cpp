double median(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();
    if (n1 > n2)
    {
        swap(a, b);
        swap(n1, n2);
    }
    int l = 0, r = n1;
    while (l <= r)
    {
        int m1 = (l + r) >> 1;
        int m2 = ((n1 + n2 + 1) >> 1) - m1;
        int l1 = m1 ? a[m1 - 1] : 1;
        int l2 = m2 ? b[m2 - 1] : 1;
        int r1 = (m1 == n1) ? 1e9 : a[m1];
        int r2 = (m2 == n2) ? 1e9 : b[m2];
        if (l1 <= r2 && l2 <= r1)
            if ((n1 + n2) % 2)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        else if (l1 > r2)
            r = m1 - 1;
        else
            l = m1 + 1;
    }
    return 0;
}
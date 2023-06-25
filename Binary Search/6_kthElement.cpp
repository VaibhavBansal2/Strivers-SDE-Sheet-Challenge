int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int &m, int &n, int &k)
{
    if (m > n)
    {
        swap(row1, row2);
        swap(m, n);
    }
    int l = max(0, k - n), r = min(k, m);
    while (l <= r)
    {
        int m1 = (l + r) >> 1;
        int m2 = k - m1;
        int l1 = m1 ? row1[m1 - 1] : 0;
        int l2 = m2 ? row2[m2 - 1] : 0;
        int r1 = (m1 == m) ? 1e5 : row1[m1];
        int r2 = (m2 == n) ? 1e5 : row2[m2];
        if (l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        else if (l1 > r2)
            r = m1 - 1;
        else
            l = m1 + 1;
    }
    return 0;
}
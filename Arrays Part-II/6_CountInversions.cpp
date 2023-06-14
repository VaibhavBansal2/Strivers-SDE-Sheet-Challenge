#include <bits/stdc++.h>
long long merge(long long *&arr, int &l, int &r, int &mid)
{
    vector<int> v1, v2;
    for (int i = l; i <= mid; i++)
        v1.push_back(*(arr + i));
    for (int i = mid + 1; i <= r; i++)
        v2.push_back(*(arr + i));
    int p1 = 0, p2 = 0, i = 0;
    long long inv = 0;
    while (p1 <= mid - l && p2 < r - mid)
        if (v1[p1] <= v2[p2])
            *(arr + l + i++) = v1[p1++];
        else
            *(arr + l + i++) = v2[p2++], inv += mid - l - p1 + 1;
    while (p1 <= mid - l)
        *(arr + l + i++) = v1[p1++];
    while (p2 < r - mid)
        *(arr + l + i++) = v2[p2++];
    return inv;
}

long long mergeSort(long long *&arr, int l, int r)
{
    if (l < r)
    {
        long long inv = 0;
        int mid = (l + r) / 2;
        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, r, mid);
        return inv;
    }
    return 0;
}

long long getInversions(long long *&arr, int &n)
{
    return mergeSort(arr, 0, n - 1);
}
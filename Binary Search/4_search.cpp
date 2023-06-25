#include <bits/stdc++.h>
int binary(int *&nums, int l, int r, int &target)
{
    int i = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (nums[m] == target)
            return m;
        if (nums[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return i;
}

int search(int *&nums, int &n, int &target)
{
    int low = 0, high = n - 1;
    while (low != high)
    {
        int mid = (low + high) / 2;
        if (nums[high] < nums[low])
            high = mid;
        else if (nums[high] > nums[low])
        {
            low = high;
            high = n - 1;
        }
    }
    low = binary(nums, 0, high, target);
    if (low != -1)
        return low;
    return binary(nums, high + 1, n - 1, target);
}
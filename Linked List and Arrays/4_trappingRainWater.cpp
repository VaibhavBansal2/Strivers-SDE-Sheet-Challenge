#include <bits/stdc++.h>
long getTrappedWater(long *&arr, int &n)
{
    int left = 0, right = n - 1;
    long ans = 0;
    long left_max = 0, right_max = 0;
    while (left < right)
        if (arr[left] < arr[right])
        {
            arr[left] >= left_max ? (left_max = arr[left]) : ans += (left_max - arr[left]);
            ++left;
        }
        else
        {
            arr[right] >= right_max ? (right_max = arr[right]) : ans += (right_max - arr[right]);
            --right;
        }
    return ans;
}
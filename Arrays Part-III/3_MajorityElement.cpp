#include <bits/stdc++.h>

int findMajorityElement(int arr[], int &n)
{
    int candidate = 0, count = 0;
    for (int i = 0; i < n; i++)
        if (!count)
        {
            candidate = arr[i];
            count++;
        }
        else if (arr[i] == candidate)
            count++;
        else
            count--;
    count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == candidate)
            count++;
    return (count > n / 2) ? candidate : -1;
}
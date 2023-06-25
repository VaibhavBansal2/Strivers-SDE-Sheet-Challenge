#include <bits/stdc++.h>

bool isFeasible(vector<int> &time, int &n, int &m, long long &mx)
{
    long long d = 1, sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (time[i] > mx)
            return false;
        if (sum + time[i] > mx)
        {
            d++;
            if (d > n)
                return false;
            sum = 0;
        }
        sum += time[i];
    }
    return true;
}

long long ayushGivesNinjatest(int &n, int &m, vector<int> &time)
{
    long long sum = 0;
    for (auto &i : time)
        sum += i;
    long long low = 1, high = sum;
    while (low < high)
    {
        long long mid = (low + high) / 2;
        if (isFeasible(time, n, m, mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
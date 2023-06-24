#include <bits/stdc++.h>

int findMinimumCoins(int &amount)
{
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int ans = 0, i = 0;
    while (amount)
    {
        if (amount >= coins[i])
        {
            int num = amount / coins[i];
            amount -= num * coins[i];
            ans += num;
        }
        i++;
    }
    return ans;
}
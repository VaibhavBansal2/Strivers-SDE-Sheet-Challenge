#include <vector>
long countWaysToMakeChange(int *&denominations, int &n, int &value)
{
    vector<long> prev(value + 1, 0), curr(value + 1, 0);
    prev[0] = 1, curr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int val = 1; val <= value; val++)
        {
            if (val >= denominations[i - 1])
                curr[val] += curr[val - denominations[i - 1]];
            curr[val] += prev[val];
        }
        // Update curr vector for the next iteration
        prev = curr;
    }
    return curr[value];
}
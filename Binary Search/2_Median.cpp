#include <bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    int R = matrix.size(), C = matrix[0].size();
    int low = 1, high = 1e5, half = (R * C) / 2, ans;
    while (low <= high)
    {
        int mid = (low + high) / 2, count = 0;
        for (int i = 0; i < R; i++)
        {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if (count > half)
                break;
        }
        if (count > half)
            ans = mid, high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}
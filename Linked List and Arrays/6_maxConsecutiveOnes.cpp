// CodeStudio

int longestSubSeg(vector<int> &arr, int &n, int &k)
{
    int ans = 0, l = 0, r = 0;
    while (r < n)
    {
        if (arr[r])
            r++;
        else if (k)
            k--, r++;
        else if (!arr[l++])
            k++;
        ans = max(ans, r - l);
    }
    return ans;
}


// Leetcode

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0, ans = 0;
        for (auto &i : nums)
            if (i)
                count++, ans = max(ans, count);
            else
                count = 0;
        return ans;
    }
};
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), i;
        for (i = n - 1; i > 0; i--)
            if (nums[i] > nums[i - 1])
                break;
        if (!i)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        i--;
        int mn = 101, idx;
        for (int j = i + 1; j < n; j++)
            if (nums[j] > nums[i])
                idx = j;
        swap(nums[i], nums[idx]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
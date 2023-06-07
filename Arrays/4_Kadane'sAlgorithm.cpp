class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, ans = *max_element(nums.begin(), nums.end());
        for (auto &i : nums)
        {
            sum += i;
            if (sum < 0)
                sum = 0;
            else
                ans = max(ans, sum);
        }
        return ans;
    }
};
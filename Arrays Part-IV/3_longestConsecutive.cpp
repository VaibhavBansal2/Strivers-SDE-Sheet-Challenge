class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> us;
        for (auto &i : nums)
            us.insert(i);
        int ans = 0;
        for (auto &i : us)
            if (us.find(i - 1) == us.end())
            {
                int count = 1;
                int x = i;
                while (us.find(x + 1) != us.end())
                    count++, x++;
                ans = max(ans, count);
            }
        return ans;
    }
};
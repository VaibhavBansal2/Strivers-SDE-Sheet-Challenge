class Solution
{
public:
    set<vector<int>> us;
    void twoSum(vector<int> &nums, int &i, int &j, int &target)
    {
        int s = j + 1, e = nums.size() - 1;
        while (s < e)
            if (nums[s] + nums[e] == target - nums[i] - nums[j] * 1ll)
                us.insert({nums[i], nums[j], nums[s], nums[e]}), s++, e--;
            else if (nums[s] + nums[e] > target - nums[i] - nums[j] * 1ll)
                e--;
            else
                s++;
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                twoSum(nums, i, j, target);
        vector<vector<int>> ans;
        for (auto &i : us)
            ans.push_back(i);
        return ans;
    }
};
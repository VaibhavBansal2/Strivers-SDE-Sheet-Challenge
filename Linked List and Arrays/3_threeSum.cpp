class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> os;
        for (int i = 0; i < n; i++)
        {
            int s = i + 1, e = n - 1;
            while (s < e)
                if (nums[s] + nums[e] == -nums[i])
                    os.insert({nums[i], nums[s++], nums[e--]});
                else if (nums[s] + nums[e] > -nums[i])
                    e--;
                else
                    s++;
        }
        vector<vector<int>> ans;
        for (auto &i : os)
            ans.push_back(i);
        return ans;
    }
};
// CodeStudio

vector<vector<int>> ans;
void rec(vector<int> &arr, int &n, int target, vector<int> &temp, int i = 0)
{
    if (i == n)
    {
        if (!target)
            ans.push_back(temp);
        return;
    }
    rec(arr, n, target, temp, i + 1);
    temp.push_back(arr[i]);
    rec(arr, n, target - arr[i], temp, i + 1);
    temp.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> &arr, int &n, int &k)
{
    vector<int> temp;
    rec(arr, n, k, temp);
    return ans;
}

// Leetcode

class Solution
{
public:
    void rec(vector<int> &candidates, vector<vector<int>> &ans, int &target, vector<int> v = {}, int i = 0, int sum = 0)
    {
        if (sum == target)
        {
            ans.push_back(v);
            return;
        }
        if (sum > target || i == candidates.size())
            return;
        rec(candidates, ans, target, v, i + 1, sum);
        v.push_back(candidates[i]);
        rec(candidates, ans, target, v, i, sum + candidates[i]);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        rec(candidates, ans, target);
        return ans;
    }
};
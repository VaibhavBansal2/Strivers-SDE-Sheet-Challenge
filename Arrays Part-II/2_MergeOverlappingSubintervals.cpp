class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1], n = intervals.size();
        vector<vector<int>> ans;
        for (int i = 1; i < n; i++)
            if (intervals[i][0] <= end)
                end = max(end, intervals[i][1]);
            else
            {
                ans.push_back({start, end});
                start = intervals[i][0], end = intervals[i][1];
            }
        if (!ans.size() || ans.back()[1] != end)
            ans.push_back({start, end});
        return ans;
    }
};
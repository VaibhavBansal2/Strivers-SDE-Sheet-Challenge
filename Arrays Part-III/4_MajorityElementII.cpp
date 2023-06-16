class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int a = 0, b = 0, c1 = 0, c2 = 0;
        for (auto &i : nums)
            if (i == a)
                c1++;
            else if (i == b)
                c2++;
            else if (!c1)
            {
                a = i;
                c1++;
            }
            else if (!c2)
            {
                b = i;
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
        c1 = c2 = 0;
        for (auto &i : nums)
            if (i == a)
                c1++;
            else if (i == b)
                c2++;
        vector<int> ans;
        if (c1 > nums.size() / 3)
            ans.push_back(a);
        if (c2 > nums.size() / 3)
            ans.push_back(b);
        return ans;
    }
};
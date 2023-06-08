// Constant Space

class Solution
{
public:
    void merge(vector<int> &nums1, int &m, vector<int> &nums2, int &n)
    {
        int p1 = 0, p2 = 0;
        while (p1 + p2 < m)
            if (p2 == n || nums1[p1] < nums2[p2])
                p1++;
            else
                p2++;
        p1 = m - 1;
        for (int i = 0; i < p2; i++)
            swap(nums1[p1--], nums2[i]);
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        for (int i = m; i < m + n; i++)
            nums1[i] = nums2[i - m];
    }
};

// Linear Time

class Solution
{
public:
    void merge(vector<int> &nums1, int &m, vector<int> &nums2, int &n)
    {
        int p1 = 0, p2 = 0;
        vector<int> v;
        while (p1 < m && p2 < n)
            if (nums1[p1] < nums2[p2])
                v.push_back(nums1[p1++]);
            else
                v.push_back(nums2[p2++]);
        while (p1 < m)
            v.push_back(nums1[p1++]);
        while (p2 < n)
            v.push_back(nums2[p2++]);
        nums1 = v;
    }
};
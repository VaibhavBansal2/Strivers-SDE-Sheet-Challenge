class Solution
{
public:
    void merge(vector<int> &nums, int &l, int &mid, int &r)
    {
        vector<int> v1, v2;
        for (int i = l; i <= mid; i++)
            v1.push_back(nums[i]);
        for (int i = mid + 1; i <= r; i++)
            v2.push_back(nums[i]);
        int p1 = 0, p2 = 0, i = l;
        while (p1 <= mid - l && p2 < r - mid)
            if (v1[p1] <= v2[p2])
                nums[i++] = v1[p1++];
            else
                nums[i++] = v2[p2++];
        while (p1 <= mid - l)
            nums[i++] = v1[p1++];
        while (p2 < r - mid)
            nums[i++] = v2[p2++];
    }

    int countPairs(vector<int> &nums, int &l, int &mid, int &r)
    {
        int right = mid + 1, ans = 0;
        for (int i = l; i <= mid; i++)
        {
            while (right <= r && nums[i] > nums[right] * 2ll)
                right++;
            ans += right - mid - 1;
        }
        return ans;
    }

    int mergeSort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int mid = (l + r) >> 1, ans = 0;
            ans += mergeSort(nums, l, mid);
            ans += mergeSort(nums, mid + 1, r);
            ans += countPairs(nums, l, mid, r);
            merge(nums, l, mid, r);
            return ans;
        }
        return 0;
    }

    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
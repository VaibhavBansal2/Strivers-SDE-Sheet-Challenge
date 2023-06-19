int removeDuplicates(vector<int> &nums, int &n)
{
    if (n == 1)
        return 1;
    int i = 1, j = 1;
    while (j < n)
        if (nums[j] <= nums[i - 1])
        {
            while (j < n && nums[j] <= nums[i - 1])
                j++;
            if (j == n)
                break;
            swap(nums[i], nums[j]);
            i++;
        }
        else
            i++, j++;
    return i;
}
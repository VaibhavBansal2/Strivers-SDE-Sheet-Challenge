class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int tortoise = nums[0], hare = nums[0];
        do
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (nums[tortoise] != nums[hare]);
        hare = nums[0];
        while (tortoise != hare)
            tortoise = nums[tortoise], hare = nums[hare];
        return tortoise;
    }
};
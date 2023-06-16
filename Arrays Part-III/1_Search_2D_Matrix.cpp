class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int &target)
    {
        int n = matrix.size(), l = 0, r = n - 1;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (matrix[m][0] == target)
                return true;
            else if (matrix[m][0] > target)
                r = m - 1;
            else if (m < n - 1 && matrix[m + 1][0] <= target)
                l = m + 1;
            else
            {
                l = m;
                break;
            }
        }
        return binary_search(matrix[l].begin(), matrix[l].end(), target);
    }
};
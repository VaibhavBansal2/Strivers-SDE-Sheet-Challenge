int singleNonDuplicate(vector<int> &arr)
{
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid] == arr[mid - 1]))
            left = mid + 1;
        else
            right = mid;
    }
    return arr[left];
}
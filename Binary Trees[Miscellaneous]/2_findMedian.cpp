#include <queue>
vector<int> findMedian(vector<int> &arr, int &n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> ans;
    for (auto &i : arr)
    {
        maxHeap.push(i);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (maxHeap.size() > minHeap.size())
            ans.push_back(maxHeap.top());
        else
            ans.push_back((maxHeap.top() + minHeap.top()) / 2);
    }
    return ans;
}
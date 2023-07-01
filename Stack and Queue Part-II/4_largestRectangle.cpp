#include <stack>
int largestRectangle(vector<int> &heights)
{
    stack<int> st;
    int mx = 0, i = 0;
    heights.push_back(0);
    while (i < heights.size())
    {
        if (st.empty() || heights[st.top()] <= heights[i])
            st.push(i++);
        else
        {
            int temp = st.top();
            st.pop();
            mx = max(mx, heights[temp] * (st.empty() ? i : i - st.top() - 1));
        }
    }
    return mx;
}
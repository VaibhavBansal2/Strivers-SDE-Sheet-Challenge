#include <bits/stdc++.h>

vector<int> NSE(vector<int> &arr, int &n)
{
    stack<int> st;
    vector<int> ans(n, n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
            ans[st.top()] = i, st.pop();
        st.push(i);
    }
    return ans;
}

vector<int> LSE(vector<int> &arr, int &n)
{
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
            ans[st.top()] = i, st.pop();
        st.push(i);
    }
    return ans;
}

vector<int> maxMinWindow(vector<int> &a, int &n)
{
    vector<int> ans(n, -1e9), left = LSE(a, n), right = NSE(a, n);
    for (int i = 0; i < n; i++)
        ans[right[i] - left[i] - 2] = max(ans[right[i] - left[i] - 2], a[i]);
    for (int i = n - 2; i >= 0; i--)
        ans[i] = max(ans[i], ans[i + 1]);
    return ans;
}
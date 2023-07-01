#include <bits/stdc++.h>
vector<int> findSpans(vector<int> &price)
{
    stack<int> st;
    vector<int> ans(price.size(), 1);
    for (int i = 0; i < price.size(); i++)
    {
        while (!st.empty() && price[st.top()] <= price[i])
            ans[i] += ans[st.top()], st.pop();
        st.push(i);
    }
    return ans;
}
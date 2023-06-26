#include <bits/stdc++.h>

void push(stack<int> &stack, int &val)
{
    if (stack.empty() || val >= stack.top())
    {
        stack.push(val);
        return;
    }
    int p = stack.top();
    stack.pop();
    push(stack, val);
    stack.push(p);
}

void sortStack(stack<int> &stack)
{
    if (!stack.empty())
    {
        int p = stack.top();
        stack.pop();
        sortStack(stack);
        push(stack, p);
    }
}
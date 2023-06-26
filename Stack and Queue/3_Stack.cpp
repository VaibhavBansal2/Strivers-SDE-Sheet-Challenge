#include <bits/stdc++.h>
class Stack
{
    queue<int> q;

public:
    Stack() {}

    int getSize() { return q.size(); }

    bool isEmpty() { return q.empty(); }

    void push(int element)
    {
        int s = q.size();
        q.push(element);
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if (q.empty())
            return -1;
        int top = q.front();
        q.pop();
        return top;
    }

    int top() { return q.empty() ? -1 : q.front(); }
};
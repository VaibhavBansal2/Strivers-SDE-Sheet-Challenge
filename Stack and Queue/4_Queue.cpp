#include <stack>
class Queue
{
    stack<int> input, output;

public:
    Queue() {}

    void enQueue(int val) { input.push(val); }

    int deQueue()
    {
        int front = peek();
        if (front != -1)
            output.pop();
        return front;
    }

    int peek()
    {
        if (isEmpty())
            return -1;
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    bool isEmpty() { return input.empty() && output.empty(); }
};
// CodeStudio (Modified Array)

#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int R, M;
    for (auto &i : arr)
        if (arr[abs(i) - 1] < 0)
            R = abs(i);
        else
            arr[abs(i) - 1] = -arr[abs(i) - 1];
    for (int i = 0; i < n; i++)
        if (arr[i] > 0)
        {
            M = i + 1;
            break;
        }
    return {M, R};
}

// InterviewBit (XOR)

bool getbit(int n, int &pos)
{
    return (n >> pos) & 1;
}

vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    int x = 0, n = A.size();
    for (auto &i : A)
        x ^= i;
    for (int i = 1; i <= n; i++)
        x ^= i;
    int pos = 0;
    for (int i = 0; i < 32; i++)
        if (getbit(x, i))
        {
            pos = i;
            break;
        }
    int a = 0;
    for (auto &i : A)
        if (getbit(i, pos))
            a ^= i;
    for (int i = 1; i <= n; i++)
        if (getbit(i, pos))
            a ^= i;
    int b = x ^ a;
    for (auto &i : A)
        if (i == a)
            return {a, b};
    return {b, a};
}
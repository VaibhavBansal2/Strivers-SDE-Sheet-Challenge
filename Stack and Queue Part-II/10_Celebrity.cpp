#include <bits/stdc++.h>
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int &n)
{
    int i = 0, j = n - 1;
    while (i < j)
        if (knows(j, i) == 1)
            j--;
        else
            i++;
    int candidate = i;
    for (i = 0; i < n; i++)
        if (i != candidate)
            if (!knows(i, candidate) || knows(candidate, i))
                return -1;
    return candidate;
}
#include <bits/stdc++.h>

int highestPowerof2(int x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 16;
    return x ^ (x >> 1);
}

int modularExponentiation(int &x, int n, int &m)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x % m;
    if (n % 2)
    {
        int p = highestPowerof2(n);
        long long m1 = modularExponentiation(x, p, m);
        long long m2 = modularExponentiation(x, n - p, m);
        return ((m1 % m) * (m2 % m)) % m;
    }
    long long ret = modularExponentiation(x, n >> 1, m);
    ret %= m;
    return (ret * ret) % m;
}
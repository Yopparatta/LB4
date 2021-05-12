#pragma once
#include <unordered_map>

#define MACRO(x,y,p,res) {\
if (y&1)\
{res = (res * x) % p;} \
y /= 2; \
x = (x * x) % p;\
}

int powmod(int x, int y, int p)
{
    int res = 1;

    x = x % p;

    while (y > 0)
    {

        MACRO(x, y, p, res);
    }
    return res;
}

int discreteLogarithm(int a, int b, int m) {

    int n = (int)sqrt(m) + 1;

    std::unordered_map<int, int> value;

    for (int i = n; i >= 1; --i)
        value[powmod(a, i * n, m)] = i;

    for (int j = 0; j < n; ++j)
    {
        int cur = (powmod(a, j, m) * b) % m;

        if (value[cur])
        {
            int ans = value[cur] * n - j;
            if (ans < m)
                return ans;
        }
    }
    return -1;
}
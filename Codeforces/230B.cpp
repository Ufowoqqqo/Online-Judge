#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool solve(long long x)
{
    long long y;
    long long i;

    y = sqrt(x);
    if(y * y != x)
        return false;

    for(i = 2; i * i <= y; i ++)
        if(!(y % i))
            return false;

    return y != 1;
}

int main(void)
{
    int n;
    int i;
    long long x;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%I64d", &x);
        puts(solve(x) ? "YES" : "NO");
    }

    return 0;
}
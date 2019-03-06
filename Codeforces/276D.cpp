#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

inline int popcount(long long x)
{
    int o;

    for(o = 0; x; x >>= 1)
        o += (x & 1);

    return o;
}

int main(void)
{
    long long l, r;
    long long o;

    scanf("%I64d %I64d", &l, &r);
    if(l == r)
        puts("0");
    else
    {
        for(o = l ^ r; popcount(o) > 1; o = o & (o - 1))
            ;
        printf("%I64d\n", (o << 1) - 1);
    }

    return 0;
}
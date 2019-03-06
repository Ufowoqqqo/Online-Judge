#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

long long C(long long x, long long y)
{
    long long i;
    long long o;

    for(i = x - y + 1, o = 1; i <= x; o *= i ++)
        ;
    for(i = 1; i <= y; o /= i ++)
        ;

    return o;
}

int main(void)
{
    long long n;

    scanf("%I64d", &n);
    printf("%I64d\n", C((n << 1) - 2, n - 1));

    return 0;
}
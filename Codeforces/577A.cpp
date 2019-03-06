#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    long long n, x;
    long long o;
    long long i;

    scanf("%I64d %I64d", &n, &x);
    for(o = 0, i = 1; i <= n; i ++)
        o += !(x % i) && x <= n * i;
    printf("%I64d\n", o);

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define calc(x) ((x) * ((x) - 1) >> 1)
using namespace std;

int main(void)
{
    long long n, m;

    scanf("%I64d %I64d", &n, &m);
    printf("%I64d %I64d\n", calc(n / m) * (m - n % m) + calc(n / m + 1) * (n % m), calc(n - m + 1));

    return 0;
}
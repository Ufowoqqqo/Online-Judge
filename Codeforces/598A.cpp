#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int t;
    long long n;
    long long i, j;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%I64d", &n);
        for(i = 1, j = 0; i <= n; i <<= 1)
            j += i;

        printf("%I64d\n", ((n * (n + 1)) >> 1) - (j << 1));
    }

    return 0;
}
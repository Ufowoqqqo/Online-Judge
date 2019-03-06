#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
#define G 1000000007LL
using namespace std;

long long f[N], g[N];

int main(void)
{
    int t, k;
    int i;
    int a, b;

    scanf("%d %d", &t, &k);

    for(i = f[0] = g[0] = 1; i < N; i ++)
    {
        f[i] = i < k ? 1 : (f[i - 1] + f[i - k]) % G;
        g[i] = (g[i - 1] + f[i]) % G;
    }

    while(t --)
    {
        scanf("%d %d", &a, &b);
        printf("%I64d\n", ((g[b] - g[a - 1]) % G + G) % G);
    }

    return 0;
}
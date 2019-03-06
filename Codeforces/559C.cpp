#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 2020
#define X 300020
#define G 1000000007LL
#define int long long
using namespace std;

long long pow(long long x, long long y)
{
    long long o;

    for(o = 1LL; y; y >>= 1, (x *= x) %= G)
        if(y & 1)
            (o *= x) %= G;

    return o;
}

pair<int, int> a[N];
long long b[X], c[X], f[N];

long long C(int n, int m)
{
    return m < 0 || m > n ? 0 : b[n] * c[n - m] % G * c[m] % G;
}

signed main(void)
{
    int h, w, n;
    int i, j;

    for(b[0] = c[0] = i = 1; i < X; i ++)
    {
        b[i] = b[i - 1] * i % G;
        c[i] = c[i - 1] * pow(i, G - 2) % G;
    }

    scanf("%I64d %I64d %I64d", &h, &w, &n);
    for(i = 0; i < n; i ++)
        scanf("%I64d %I64d", &a[i].first, &a[i].second);
    a[n] = make_pair(h, w);

    sort(a, a + n + 1);
    for(i = 0; i <= n; i ++)
    {
        f[i] = C(a[i].first + a[i].second - 2, a[i].first - 1);
        for(j = 0; j < i; j ++)
            f[i] = (f[i] - f[j] * C((a[i].first - a[j].first) + (a[i].second - a[j].second), a[i].first - a[j].first)) % G;
        f[i] = (f[i] + G) % G;
    }

    printf("%I64d\n", f[n]);

    return 0;
}
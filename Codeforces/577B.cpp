#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000020
#define M 1020
using namespace std;

int a[N];
bool f[M], g[M];

int main(void)
{
    int n, m;
    int i, j;

    scanf("%d %d", &n, &m);

    if(m < n)
    {
        puts("YES");

        return 0;
    }

    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        a[i] %= m;
        g[a[i]] = true;
        for(j = 1; j < m; j ++)
            g[(j + a[i]) % m] = f[j];
        if(g[0])
        {
            puts("YES");

            return 0;
        }

        for(j = 0; j < m; j ++)
            f[j] |= g[j];
    }

    puts("NO");

    return 0;
}
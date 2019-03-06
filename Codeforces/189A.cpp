#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 4020
using namespace std;

int f[N];
bool g[N];

int main(void)
{
    int n, a, b, c;
    int i;

    scanf("%d %d %d %d", &n, &a, &b, &c);
    for(g[0] = true, i = min(a, min(b, c)); i <= n; i ++)
    {
        if(a <= i && g[i - a])
            f[i] = max(f[i], f[i - a] + 1);
        if(b <= i && g[i - b])
            f[i] = max(f[i], f[i - b] + 1);
        if(c <= i && g[i - c])
            f[i] = max(f[i], f[i - c] + 1);
        g[i] = !!f[i];
    }
    printf("%d\n", f[n]);

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
#define M 1000
using namespace std;

int a[N], x[M], y[M];

int main(void)
{
    int n, m;
    int i;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    scanf("%d", &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%d %d", &x[i], &y[i]);
        a[x[i] - 1] += y[i] - 1;
        a[x[i] + 1] += a[x[i]] - y[i];
        a[x[i    ]] = 0;
    }

    for(i = 1; i <= n; i ++)
        printf("%d\n", a[i]);

    return 0;
}
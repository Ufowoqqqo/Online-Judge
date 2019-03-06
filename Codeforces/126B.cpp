#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 1000020
#define T 22
#define MIN(a, b) ((a)<(b)?(a):(b))
#define MAX(a, b) ((b)<(a)?(a):(b))
using std::swap;

char s[N];
int n, a[N], c[N], h[N][T], r[N], p[N], q[N];

int query(int x, int y)
{
    int d;

    d = log2(y - x + 1);

    return MIN(h[x][d], h[y - (1 << d) + 1][d]);
}

bool check(int k)
{
    int t;

    t = query(MIN(r[1], r[n - k + 1]) + 1, MAX(r[1], r[n - k + 1]));
    if(t < k)
        return false;

    if(r[n - k + 1] + 1 < r[1] || r[1] + 1 < r[n - k + 1])
        return true;

    t = MIN(r[1], r[n - k + 1]);
    return ((t > 1 && k <= h[t][0]) || ((t + 1 < n) && k <= h[t + 2][0]));
}

int main(void)
{
    int m, t;
    int i, j, l, p, k;
    int *x, *y;

    freopen("t.in" , "r", stdin );

    scanf("%s", s + 1);
    for(i = 1, n = strlen(s + 1), m = 0, x = ::p, y = q; i <= n; i ++)
    {
        m = MAX(m, x[i] = s[i] - 'a' + 1);
        ++ c[x[i]];
    }
    for(i = 1; i <= m; i ++)
        c[i] += c[i - 1];
    for(i = n; i; i --)
        a[c[x[i]] --] = i;

    for(l = 1; l <= n; l <<= 1)
    {
        for(p = 0, i = n - l + 1; i <= n; i ++)
            y[++ p] = i;
        for(i = 1; i <= n; i ++)
            if(l < a[i])
                y[++ p] = a[i] - l;

        memset(c, 0, sizeof c);
        for(i = 1; i <= n; i ++)
            ++ c[x[y[i]]];
        for(i = 1; i <= m; i ++)
            c[i] += c[i - 1];
        for(i = n; i; i --)
            a[c[x[y[i]]] --] = y[i];

        swap(x, y);
        x[a[1]] = m = 1;
        for(i = 2; i <= n; i ++)
            if(y[a[i]] == y[a[i - 1]] && y[a[i] + l] == y[a[i - 1] + l])
                x[a[i]] = m;
            else
                x[a[i]] = ++ m;
        if(m == n)
            break;
    }

    for(i = 1; i <= n; i ++)
        ::r[a[i]] = i;

    for(i = 1, k = 0; i <= n; i ++)
    {
        if(k) -- k;
        if(::r[i])
            while(s[i + k] == s[a[::r[i] - 1] + k])
                ++ k;
        h[::r[i]][0] = k;
    }

    for(i = 1, t = log2(n); i <= t; i ++)
        for(j = 1; j + (1 << i) <= n + 1; j ++)
            h[j][i] = MIN(h[j][i - 1], h[j + (1 << (i - 1))][i - 1]);

    for(i = n - 2; i > 0; i --)
        if(check(i))
        {
            for(j = 1; j <= i; j ++)
                putchar(s[j]);
            putchar('\n');

            return 0;
        }
    puts("Just a legend");

    return 0;
}
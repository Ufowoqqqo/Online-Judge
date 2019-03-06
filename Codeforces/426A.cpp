#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
using namespace std;

int a[N];

int main(void)
{
    int n, s;
    int i;
    int w, m;

    scanf("%d %d", &n, &s);
    for(i = 1, w = m = 0; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        w += a[i];
        m = max(m, a[i]);
    }

    puts(w <= m + s ? "YES" : "NO");

    return 0;
}
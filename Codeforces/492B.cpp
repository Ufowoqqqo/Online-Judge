#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1020
using namespace std;

int a[N];

int main(void)
{
    int n, l;
    int i;
    int o;

    scanf("%d %d", &n, &l);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    sort(a, a + n);

    o = max(a[0], l - a[n - 1]) << 1;
    for(i = 1; i < n; i ++)
        o = max(o, a[i] - a[i - 1]);
    printf("%.9lf\n", o / 2.0);

    return 0;
}
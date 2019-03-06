#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 300020
using namespace std;

long long a[N];

int main(void)
{
    int n;
    int i;
    long long s, o;

    scanf("%d", &n);
    for(i = 1, s = 0; i <= n; i ++)
    {
        scanf("%I64d", &a[i]);
        s += a[i];
    }

    sort(a + 1, a + n + 1);
    for(i = 1, o = -a[n]; i <= n; i ++)
    {
        o += s + a[i];
        s -= a[i];
    }

    printf("%I64d\n", o);

    return 0;
}
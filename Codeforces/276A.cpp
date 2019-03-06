#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100000
using namespace std;

int f[N], t[N];

int main(void)
{
    int n, k;
    int i;
    int o;

    scanf("%d %d", &n, &k);
    for(i = 0, o = -1000000020; i < n; i ++)
    {
        scanf("%d %d", &f[i], &t[i]);
        o = max(o, k < t[i] ? f[i] - (t[i] - k) : f[i]);
    }

    printf("%d\n", o);

    return 0;
}
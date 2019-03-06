#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 120
using namespace std;

int a[N];

int main(void)
{
    int n;
    int i, j, k;
    int o, t;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    for(o = 0, i = 1; i <= n; i ++)
        for(j = i; j <= n; j ++)
        {
            for(t = 0, k = 1; k < i; k ++)
                t += a[k];
            for(k = i; k <= j; k ++)
                t += !a[k];
            for(k = j + 1; k <= n; k ++)
                t += a[k];
            o = max(o, t);
        }
    printf("%d\n", o);

    return 0;
}
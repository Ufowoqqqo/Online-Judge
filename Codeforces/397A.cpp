#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1020
using namespace std;

int l[N], r[N], a[N];

int main(void)
{
    int n, o;
    int i, j;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d %d", &l[i], &r[i]);
        for(j = l[i] + 1; j <= r[i]; j ++)
            ++ a[j];
    }

    for(o = 0, i = l[0] + 1; i <= r[0]; i ++)
        o += a[i] == 1;
    printf("%d\n", o);

    return 0;
}
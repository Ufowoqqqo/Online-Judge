#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 50
using namespace std;

int h[N], a[N];

int main(void)
{
    int n;
    int i, j;
    int o;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d %d", &h[i], &a[i]);

    for(i = o = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            o += (h[i] == a[j]) * !!(i ^ j);

    printf("%d\n", o);

    return 0;
}
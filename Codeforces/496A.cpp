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
    int n;
    int i, j;
    int t, o;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    for(i = 2, o = 1001; i < n; i ++)
    {
        for(j = 2, t = 0; j <= n; j ++)
            if(j != i)
                t = max(t, a[j] - a[j == i + 1 ? i - 1 : j - 1]);
        o = min(o, t);
    }

    printf("%d\n", o);

    return 0;
}
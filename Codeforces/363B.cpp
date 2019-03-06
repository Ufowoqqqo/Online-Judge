#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 150020
using namespace std;

int h[N], f[N];

int main(void)
{
    int n, k;
    int i;
    int o, s;

    scanf("%d %d", &n, &k);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &h[i]);
        f[i] = f[i - 1] + h[i];
    }

    for(i = 2, o = 1, s = f[k]; i + k <= n + 1; i ++)
        if(f[i + k - 1] < f[i - 1] + s)
        {
            s = f[i + k - 1] - f[i - 1];
            o = i;
        }

    printf("%d\n", o);

    return 0;
}
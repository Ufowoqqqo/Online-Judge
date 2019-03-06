#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 120
#define G 1000000007
using namespace std;

long long f[N][2];

int main(void)
{
    int n, k, d;
    int i, j;

    scanf("%d %d %d", &n, &k, &d);
    f[0][0] = 1;

    for(i = 0; i < n; i ++)
    {
        if(f[i][0])
            for(j = 1; j <= k && i + j <= n; j ++)
                (f[i + j][d <= j] += f[i][0]) %= G;
        if(f[i][1])
            for(j = 1; j <= k && i + j <= n; j ++)
                (f[i + j][1] += f[i][1]) %= G;
    }

    printf("%I64d\n", f[n][1]);

    return 0;
}
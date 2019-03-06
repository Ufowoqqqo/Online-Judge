#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define G 100000000LL
#define N 120
#define K 12
using namespace std;

long long f[N << 1][N][2][N];

int main(void)
{
    int n1, n2, k1, k2;
    int i, j, k;
    long long o;

    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    for(i = 2, f[1][1][0][1] = f[1][1][1][0] = 1, k1 = min(k1, n1), k2 = min(k2, n2); i <= n1 + n2; i ++)
    {
        if(i <= k2)
        	f[i][i][1][0] = 1;
        for(k = 1; k <= n1 && k <= i; k ++)
        {
            for(j = 1; j + k <= i && j <= k2; j ++)
                (f[i][1][0][k] += f[i - 1][j][1][k - 1]) %= G;
            if(k < i)
            	for(j = 1; j <= k; j ++)
	                (f[i][1][1][k] += f[i - 1][j][0][k]) %= G;
            for(j = 2; j <= min(k, k1); j ++)
                f[i][j][0][k] = f[i - 1][j - 1][0][k - 1];
            for(j = 2; j + k <= i && j <= k2; j ++)
                f[i][j][1][k] = f[i - 1][j - 1][1][k];
        }
    }

    for(i = 1, o = 0; i <= k1; i ++)
        (o += f[n1 + n2][i][0][n1]) %= G;
    for(i = 1       ; i <= k2; i ++)
        (o += f[n1 + n2][i][1][n1]) %= G;
    printf("%I64d\n", o);

    return 0;
}
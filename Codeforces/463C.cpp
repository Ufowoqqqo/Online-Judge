#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 2020
using namespace std;

int n;
long long a[N][N];
long long f[N << 1], g[N << 1];
long long o[2];

int main(void)
{
    int i, j;
    int t;
    pair<int, int> p[2];

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        for(j = 1; j <= n; j ++)
        {
            scanf("%I64d", &a[i][j]);
            f[i - j + n] += a[i][j];
            g[i + j    ] += a[i][j];
        }

    for(i = 1; i <= n; i ++)
    	for(j = 1; j <= n; j ++)
    	{
    		t = (i + j) & 1;
    		if(o[t] <= f[i - j + n] + g[i + j] - a[i][j])
    		{
    			o[t] = f[i - j + n] + g[i + j] - a[i][j];
    			p[t] = make_pair(i, j);
    		}
    	}
    printf("%I64d\n%d %d %d %d\n", o[0] + o[1], p[0].first, p[0].second, p[1].first, p[1].second);

    return 0;
}
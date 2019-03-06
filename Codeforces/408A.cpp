#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
using namespace std;

int k[N], c[N];
int m[N][N];

int main(void)
{
    int n;
    int i, j;
    int o;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &k[i]);
        c[i] = k[i] * 3;
    }

    for(i = 0, o = 100000000; i < n; i ++)
    {
        for(j = 0; j < k[i]; j ++)
        {
            scanf("%d", &m[i][j]);
            c[i] += m[i][j];
        }
        o = min(o, c[i]);
    }
    printf("%d\n", o * 5);

    return 0;
}
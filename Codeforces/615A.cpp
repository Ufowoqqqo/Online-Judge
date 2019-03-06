#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
#define M 1000
using namespace std;

bool a[M];
int x[N], y[N][M];

int main(void)
{
    int n, m;
    int i, j;
    bool o;

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &x[i]);
        for(j = 0; j < x[i]; j ++)
        {
            scanf("%d", &y[i][j]);
            a[y[i][j]] = true;
        }
    }

    for(i = 1, o = true; i <= m; o &= a[i ++])
        ;
    puts(o ? "YES" : "NO");

    return 0;
}
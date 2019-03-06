#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 120
using namespace std;

int a[N], b[N];

int main(void)
{
    int n, m;
    int i, j, k;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i ++)
    {
        for(j = 1, k = 1; j <= n; j ++)
        {
            scanf("%d", &a[j]);
            if(a[k] < a[j])
                k = j;
        }
        ++ b[k];
    }

    for(i = 1, j = 1; i <= n; i ++)
        if(b[j] < b[i])
            j = i;
    printf("%d\n", j);

    return 0;
}
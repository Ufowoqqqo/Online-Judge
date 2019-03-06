#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
using namespace std;

int b[N], o[N];

int main(void)
{
    int n, m;
    int i, j;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i ++)
    {
        scanf("%d", &b[i]);
        for(j = b[i]; j <= n; j ++)
            if(!o[j])
                o[j] = b[i];
    }

    for(i = 1; i <= n; i ++)
        printf("%d ", o[i]);

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n, m;
    int i, j;
    int o;

    scanf("%d %d", &n, &m);
    for(i = o = 0; i <= n && i <= m; i ++)
        for(j = 0; j <= n && j <= m; j ++)
            o += i * i + j == n && i + j * j == m;

    printf("%d\n", o);

    return 0;
}
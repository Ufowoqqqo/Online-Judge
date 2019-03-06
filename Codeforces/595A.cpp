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
    int x, y;
    int o;

    scanf("%d %d", &n, &m);
    for(i = o = 0; i < n; i ++)
        for(j = 0; j < m; j ++)
        {
            scanf("%d %d", &x, &y);
            o += (x | y);
        }
    printf("%d\n", o);

    return 0;
}
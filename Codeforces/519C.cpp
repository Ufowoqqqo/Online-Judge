#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n, m;
    int i;
    int o;

    scanf("%d %d", &n, &m);
    for(i = o = 0; i <= n; i ++)
        if((i << 1) <= m)
            o = max(o, i + min((n - i) >> 1, m - (i << 1)));

    printf("%d\n", o);

    return 0;
}
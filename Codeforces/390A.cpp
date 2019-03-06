#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int f[120], g[120];

int main(void)
{
    int n;
    int i;
    int x, y, a, b;

    scanf("%d", &n);
    for(i = a = b = 0; i < n; i ++)
    {
        scanf("%d %d", &x, &y);
        a += !(f[x] ++);
        b += !(g[y] ++);
    }
    printf("%d\n", min(a, b));

    return 0;
}
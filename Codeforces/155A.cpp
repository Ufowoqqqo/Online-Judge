#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n, o;
    int l, r, x;
    int i;

    scanf("%d", &n);
    scanf("%d", &l);
    for(i = 1, r = l, o = 0; i < n; i ++)
    {
        scanf("%d", &x);
        o += x < l || x > r;
        l = min(l, x);
        r = max(r, x);
    }
    printf("%d\n", o);

    return 0;
}
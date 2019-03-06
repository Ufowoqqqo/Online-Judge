#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
using namespace std;

int h[N];

int main(void)
{
    int n;
    int i;
    int o;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d", &h[i]);

    for(i = 2, o = (n << 1) + h[1] - 1; i <= n; i ++)
        o += abs(h[i - 1] - h[i]);

    printf("%d\n", o);

    return 0;
}
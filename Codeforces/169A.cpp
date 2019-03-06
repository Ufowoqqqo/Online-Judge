#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 20000
using namespace std;

int h[N];

int main(void)
{
    int n, a, b;
    int i;

    scanf("%d %d %d", &n, &a, &b);
    for(i = 1; i <= n; i ++)
        scanf("%d", &h[i]);

    sort(h + 1, h + n + 1);
    printf("%d\n", h[b + 1] - h[b]);

    return 0;
}
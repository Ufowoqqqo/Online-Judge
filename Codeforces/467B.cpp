#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define M 1020
using namespace std;

int x[M];

int main(void)
{
    int n, m, k;
    int i, o;

    scanf("%d %d %d", &n, &m, &k);
    for(i = 0; i <= m; i ++)
        scanf("%d", &x[i]);

    for(i = o = 0; i < m; i ++)
        o += __builtin_popcount(x[i] ^ x[m]) <= k;
    printf("%d\n", o);

    return 0;
}
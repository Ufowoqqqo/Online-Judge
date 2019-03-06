#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100000
using namespace std;

int l[N], r[N];
int c[2][10];

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d %d", &l[i], &r[i]);
        ++ c[0][l[i]];
        ++ c[1][r[i]];
    }

    printf("%d\n", (n << 1) - max(c[0][0], c[0][1]) - max(c[1][0], c[1][1]));

    return 0;
}
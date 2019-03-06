#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
using namespace std;

char s[N][N];
int r[N], c[N];

int main(void)
{
    int n;
    int i, j;
    int o;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%s", s[i]);
        for(j = 0; j < n; j ++)
        {
            r[i] += s[i][j] == 'C';
            c[j] += s[i][j] == 'C';
        }
    }

    for(i = o = 0; i < n; i ++)
        o += ((r[i] * (r[i] - 1)) >> 1) + ((c[i] * (c[i] - 1)) >> 1);
    printf("%d\n", o);

    return 0;
}
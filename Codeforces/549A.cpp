#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 500
#define M 500
using namespace std;

const int d[2][4] = {{0, 0, 1, 1}, {0, 1, 0, 1}};

char s[N][M], t[10];

int main(void)
{
    int n, m;
    int i, j, k;
    int o;

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i ++)
        scanf("%s", s[i]);

    for(i = o = 0; i + 1 < n; i ++)
        for(j = 0; j + 1 < m; j ++)
        {
            for(k = 0; k < 4; k ++)
                t[k] = s[i + d[0][k]][j + d[1][k]];
            sort(t, t + 4);
            o += !strcmp(t, "acef");
        }

    printf("%d\n", o);

    return 0;
}
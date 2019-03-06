#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 3
using namespace std;

const int d[2][5] = {{-1, 0, 0, 0, 1},
                     {0, -1, 0, 1, 0}};

int a[N][N], o[N][N];

int main(void)
{
    int i, j, k, l;
    int x, y;

    for(i = 0; i < N; i ++)
        for(j = 0; j < N; j ++)
            o[i][j] = 1;

    for(i = 0; i < N; i ++)
        for(j = 0; j < N; j ++)
        {
            scanf("%d", &a[i][j]);
            for(k = 0; k < a[i][j]; k ++)
                for(l = 0; l < 5; l ++)
                {
                    x = i + d[0][l];
                    y = j + d[1][l];
                    if(0 <= x && x < N && 0 <= y && y < N)
                        o[x][y] ^= 1;
                }
        }

    for(i = 0; i < N; i ++)
    {
        for(j = 0; j < N; j ++)
            putchar(o[i][j] + '0');
        putchar('\n');
    }

    return 0;
}
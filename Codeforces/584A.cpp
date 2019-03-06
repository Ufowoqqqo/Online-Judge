#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 120
#define T 20
using namespace std;

int f[N][T][20];
char o[N];

int main(void)
{
    int n, t;
    int i, j, k, l;
    int x;
    bool v;

    scanf("%d %d", &n, &t);

    memset(f, -1, sizeof f);
    for(i = 1; i < 10; i ++)
        f[1][i % t][i] = 0;

    for(i = 1; i < n; i ++)
        for(j = 0; j < t; j ++)
            for(k = 0; k < 10; k ++)
                if(f[i][j][k] != -1)
                    for(l = 0; l < 10; l ++)
                        f[i + 1][(j * 10 + l) % t][l] = j;

    for(i = 0, v = false; i < 10; i ++)
        v |= f[n][0][i] != -1;
    if(!v)
        puts("-1");
    else
    {
        for(i = n, x = 0; i; x = f[i --][x][j])
        {
            for(j = 0; f[i][x][j] == -1; j ++)
                ;
            o[i - 1] = j + '0';
        }

        puts(o);
    }

    return 0;
}
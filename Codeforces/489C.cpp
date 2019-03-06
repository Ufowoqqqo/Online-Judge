#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define M 120
#define S 920
using namespace std;

bool f[M][S][20];

int main(void)
{
    int m, s;
    int i, j, k, l;
    int x;
    bool o;

    scanf("%d %d", &m, &s);

    if(m == 1)
    {
        if(s > 9)
            puts("-1 -1");
        else
            printf("%d %d\n", s, s);

        return 0;
    }

    for(i = 0; i < 10; i ++)
        f[1][i][i] = true;

    for(i = 1; i < m; i ++)
        for(j = 0; j <= s; j ++)
            for(k = 0; k < 10; k ++)
                if(f[i][j][k])
                    for(l = 0; l < 10 && j + l <= s; l ++)
                        f[i + 1][j + l][l] = true;

    for(i = 1, o = false; i < 10; i ++)
        if(f[m][s][i])
            o = true;
    if(!o)
        puts("-1 -1");
    else
    {
        for(i = 0, x = s; i < m; i ++, x -= j)
        {
            for(j = !i; !f[m - i][x][j]; j ++)
                ;
            putchar(j + '0');
        }
        putchar('\n');


        for(i = 0, x = s; i < m; i ++, x -= j)
        {
            for(j = 9; !f[m - i][x][j]; j --)
                ;
            putchar(j + '0');
        }
        putchar('\n');
    }

    return 0;
}
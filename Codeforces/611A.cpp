#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

char t[10], s[10];
int c[10][100];

inline int maxday(int m)
{
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    if(m == 2)
        return 29;

    return 30;
}

int main(void)
{
    int i;
    int m, d, w;
    int x;

    for(i = 0, m = d = 1, w = 5; i < 366; i ++)
    {
        ++ c[0][w];
        ++ c[1][d];
        if(d == maxday(m))
        {
            ++ m;
            d = 1;
        }
        else
            ++ d;

        if(++ w == 8)
            w = 1;
    }

    scanf("%d %s %s", &x, t, s);

    if(!strcmp(s, "week"))
        printf("%d\n", c[0][x]);
    if(!strcmp(s, "month"))
        printf("%d\n", c[1][x]);

    return 0;
}
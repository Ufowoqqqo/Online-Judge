#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100
using namespace std;

char s1[N], s2[N];

double solve(int x, int y)
{
    int u, c;
    int i, j, k;

    for(i = c = 0, u = 1 << y; i < u; i ++)
    {
        for(j = k = 0; j < y; j ++)
            k += (i & (1 << j) ? 1 : -1);
        c += k == x;
    }

    return (double)c / u;
}

int main(void)
{
    int p, q, c;
    int i;

    scanf("%s", s1);
    scanf("%s", s2);

    for(i = p = 0; s1[i]; i ++)
        p += s1[i] == '+' ? 1 : -1;
    for(i = q = c = 0; s2[i]; i ++)
    {
        if(s2[i] == '+')
            ++ q;
        if(s2[i] == '-')
            -- q;
        if(s2[i] == '?')
            ++ c;
    }

    printf("%.9lf\n", solve(p - q, c));

    return 0;
}
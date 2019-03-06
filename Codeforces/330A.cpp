#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 20
using namespace std;

char s[N][N];
bool x[N], y[N];

int main(void)
{
    int r, c;
    int i, j;
    int p, q;

    scanf("%d %d", &r, &c);
    for(i = 0; i < r; i ++)
    {
        scanf("%s", s[i]);
        for(j = 0; j < c; j ++)
        {
            x[i] |= s[i][j] == 'S';
            y[j] |= s[i][j] == 'S';
        }
    }

    for(i = p = 0; i < r; i ++)
        p += !x[i];
    for(i = q = 0; i < c; i ++)
        q += !y[i];
    printf("%d\n", p * c + q * r - p * q);

    return 0;
}
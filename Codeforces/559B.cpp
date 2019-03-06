#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 200020
#define B 31
using namespace std;

char s[N], t[N];
unsigned long long p[N], h[2][N];
int c[2][N][30];

inline unsigned long long f(int k, int l, int r)
{
    return h[k][r] - h[k][l - 1] * p[r - l + 1];
}

bool check(int l, int r, int x, int y)
{
    int n, m;
    int i;

    if(f(0, l, r) == f(1, x, y))
        return true;

    if((r - l + 1) & 1)
        return false;

    for(i = 0; i < 26; i ++)
        if(c[0][r][i] + c[1][x - 1][i] != c[1][y][i] + c[0][l - 1][i])
            return false;

    n = (l + r) >> 1;
    m = (x + y) >> 1;

    return (check(l, n, x, m) && check(n + 1, r, m + 1, y)) || (check(l, n, m + 1, y) && check(n + 1, r, x, m));
}

int main(void)
{
    int n;
    int i, j;

    scanf("%s", s + 1);
    scanf("%s", t + 1);

    n = strlen(s + 1);

    for(i = p[0] = 1; i <= n; i ++)
    {
        p[i] = p[i - 1] * B;
        h[0][i] = h[0][i - 1] * B + s[i] - 'a' + 1;
        h[1][i] = h[1][i - 1] * B + t[i] - 'a' + 1;
        for(j = 0; j < 26; j ++)
        {
            c[0][i][j] = c[0][i - 1][j];
            c[1][i][j] = c[1][i - 1][j];
        }
        ++ c[0][i][s[i] - 'a'];
        ++ c[1][i][t[i] - 'a'];
    }

    puts(check(1, n, 1, n) ? "YES" : "NO");

    return 0;
}
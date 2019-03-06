#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
using namespace std;

char s[N];
int f[N];

int main(void)
{
    int n, m;
    int i;
    int l, r;

    scanf("%s", s + 1);
    n = strlen(s + 1);
    for(i = 1; i <= n; i ++)
        f[i] = f[i - 1] + (s[i] == s[i + 1]);

    scanf("%d", &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", f[r - 1] - f[l - 1]);
    }

    return 0;
}
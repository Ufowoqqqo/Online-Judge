#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 500020
using namespace std;

int n, s[N];

bool check(int k)
{
    int i, j;

    for(i = 0, j = k; i < k; i ++)
    {
        for(; j < n && s[j] < (s[i] << 1); j ++)
            ;
        if(j == n)
            return false;
        ++ j;
    }

    return true;
}

int main(void)
{
    int i;
    int l, r, m;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d", &s[i]);

    sort(s, s + n);

    for(l = 0, r = (n >> 1) + 1; l + 1 < r; )
    {
        m = (l + r) >> 1;
        (check(m) ? l : r) = m;
    }

    printf("%d\n", n - l);

    return 0;
}
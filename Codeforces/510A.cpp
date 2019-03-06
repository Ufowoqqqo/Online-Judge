#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 120
using namespace std;

int main(void)
{
    int n, m;
    int i, j;

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < m; j ++)
            putchar(!(i & 1) || ( (i & 1) && ((((i >> 1) & 1) && !j) || (!((i >> 1) & 1) && (j + 1 == m)))) ? '#' : '.');
        putchar('\n');
    }

    return 0;
}
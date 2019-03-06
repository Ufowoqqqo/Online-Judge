#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int i, j;

    scanf("%d", &n);

    for(i = 1; i <= n; i ++)
    {
        for(j = 1; j <= n; j ++)
            printf("%d ", (j - 1) * n + (j & 1 ? i : n - i + 1));
        putchar('\n');
    }

    return 0;
}
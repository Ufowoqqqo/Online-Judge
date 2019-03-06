#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int f[10000];

int main(void)
{
    int n, m;
    int i, j, k;

    for(m = 2, f[1] = 1; f[m - 1] < 1000000000; m ++)
        f[m] = f[m - 2] + f[m - 1];

    scanf("%d", &n);

    for(i = 0; i < m; i ++)
        for(j = 0; j < m; j ++)
            for(k = 0; k < m; k ++)
                if(f[i] + f[j] + f[k] == n)
                {
                    printf("%d %d %d\n", f[i], f[j], f[k]);

                    return 0;
                }

    puts("I'm too stupid to solve this problem");

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n, m, k;
    int i;

    scanf("%d %d", &n, &m);
    for(k = ((n - 1) >> 1) + 1, i = m; i <= n; i += m)
        if(k <= i)
        {
            printf("%d\n", i);

            return 0;
        }
    puts("-1");

    return 0;
}
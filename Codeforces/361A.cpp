#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n, k;
    int i, j;

    scanf("%d %d", &n, &k);

    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j ++)
            printf("%d ", i == j ? k : 0);
        putchar('\n');
    }

    return 0;
}
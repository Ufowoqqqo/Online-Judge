#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 120
using namespace std;

int main(void)
{
    int n;
    int i, j;
    int o;
    int a;

    scanf("%d", &n);
    for(i = o = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
        {
            scanf("%d", &a);
            if(i == j || i + j + 1 == n || i == (n >> 1) || j == (n >> 1))
                o += a;
        }
    printf("%d\n", o);

    return 0;
}
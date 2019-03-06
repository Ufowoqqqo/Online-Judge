#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1020
using namespace std;

int h[N];

int main(void)
{
    int n, d;
    int i, j;
    int o;

    scanf("%d %d", &n, &d);
    for(i = 0; i < n; i ++)
        scanf("%d", &h[i]);

    for(i = o = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            if(i != j)
                o += abs(h[i] - h[j]) <= d;
    printf("%d\n", o);

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
using namespace std;

int o[N];

int main(void)
{
    int n, a, b;
    int i;
    int p;

    scanf("%d %d %d", &n, &a, &b);
    for(i = 0; i < a; i ++)
    {
        scanf("%d", &p);
        o[p] = 1;
    }
    for(i = 0; i < b; i ++)
    {
        scanf("%d", &p);
        o[p] = 2;
    }

    for(i = 1; i <= n; i ++)
        printf("%d ", o[i]);

    return 0;
}
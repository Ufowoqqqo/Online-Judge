#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
using namespace std;

int d[N];

int main(void)
{
    int n;
    int a, b;
    int i;

    scanf("%d", &n);
    for(i = 1; i < n; i ++)
    {
        scanf("%d", &d[i]);
        d[i] += d[i - 1];
    }

    scanf("%d %d", &a, &b);

    printf("%d\n", d[b - 1] - d[a - 1]);

    return 0;
}
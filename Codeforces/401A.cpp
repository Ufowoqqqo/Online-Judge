#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 10000
using namespace std;

int a[N];

int main(void)
{
    int n, x;
    int i;
    int s;

    scanf("%d %d", &n, &x);
    for(i = s = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        s += a[i];
    }

    printf("%d\n", abs(s) ? (abs(s) - 1) / x + 1 : 0);

    return 0;
}
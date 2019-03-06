#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
using namespace std;

int a[N];

int main(void)
{
    int n;
    int i;
    int t;
    long long o;

    scanf("%d", &n);
    for(i = o = 0, t = 1000000001; i < n; i ++)
    {
        scanf("%d", &a[i]);
        o += a[i];
        if(a[i] & 1)
            t = min(t, a[i]);
    }

    printf("%I64d\n", o - (o & 1 ? t : 0));

    return 0;
}
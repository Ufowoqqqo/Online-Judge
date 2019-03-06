#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
using namespace std;

long long a[N];

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%I64d", &a[i]);

    printf("%I64d %I64d\n", a[2] - a[1], a[n] - a[1]);
    for(i = 2; i < n; i ++)
        printf("%I64d %I64d\n", min(a[i] - a[i - 1], a[i + 1] - a[i]), max(a[i] - a[1], a[n] - a[i]));
    printf("%I64d %I64d\n", a[n] - a[n - 1], a[n] - a[1]);

    return 0;
}
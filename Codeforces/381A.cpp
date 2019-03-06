#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1020
using namespace std;

int a[N];

int main(void)
{
    int n;
    int i, j, k;
    int o[2];

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);

    for(i = k = o[0] = o[1] = 0, j = n - 1; i <= j; k ^= 1)
        if(a[i] < a[j])
            o[k] += a[j --];
        else
            o[k] += a[i ++];

    printf("%d %d\n", o[0], o[1]);

    return 0;
}
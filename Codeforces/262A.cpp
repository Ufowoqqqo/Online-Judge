#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000

using namespace std;

int a[N];

int main(void)
{
    int n, k;
    int i;
    int o, c;

    scanf("%d %d", &n, &k);
    for(i = o = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        for(c = 0; a[i]; a[i] /= 10)
            c += a[i] % 10 == 4 || a[i] % 10 == 7;
        o += c <= k;
    }

    printf("%d\n", o);

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
using namespace std;

int a[N], b[N];

int main(void)
{
    int n;
    int i;
    int l, r;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    for(i = 1, l = n + 1, r = 0; i <= n; i ++)
        if(a[i] != b[i])
        {
            l = min(l, i);
            r = max(r, i);
        }
    
    if(r < l)
        l = r = 1;

    reverse(a + l, a + r + 1);

    for(i = 1; i <= n; i ++)
        if(a[i] != b[i])
        {
            puts("no");

            return 0;
        }

    puts("yes");
    printf("%d %d\n", l, r);

    return 0;
}
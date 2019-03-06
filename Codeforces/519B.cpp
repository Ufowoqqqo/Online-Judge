#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
using namespace std;

int a[N], b[N], c[N];

int main(void)
{
    int n;
    int i;
    bool v;

    scanf("%d", &n);
    for(i = 0; i     < n; i ++)
        scanf("%d", &a[i]);
    for(i = 0; i + 1 < n; i ++)
        scanf("%d", &b[i]);
    for(i = 0; i + 2 < n; i ++)
        scanf("%d", &c[i]);

    sort(a, a + n    );
    sort(b, b + n - 1);
    sort(c, c + n - 2);

    for(i = 0, v = false; i + 1 < n && !v; i ++)
        if(a[i] != b[i])
        {
            printf("%d\n", a[i]);
            v = true;
        }
    if(!v)
        printf("%d\n", a[n - 1]);

    for(i = 0, v = false; i + 2 < n && !v; i ++)
        if(b[i] != c[i])
        {
            printf("%d\n", b[i]);
            v = true;
        }
    if(!v)
        printf("%d\n", b[n - 2]);

    return 0;
}
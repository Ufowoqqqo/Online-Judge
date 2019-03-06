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
    int n, m;
    int i;
    int s;

    scanf("%d", &n);
    scanf("%d", &m);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);

    sort(a, a + n, greater<int>());
    for(i = s = 0; i < n && s < m; i ++)
        s += a[i];

    printf("%d\n", i);

    return 0;
}
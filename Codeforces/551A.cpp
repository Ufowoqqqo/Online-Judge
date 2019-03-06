#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 2020
using namespace std;

typedef pair<int, int> pii;

pii a[N];
int o[N];

int main(void)
{
    int n;
    int i, j;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a + 1, a + n + 1, greater<pii>());
    for(i = 1; i <= n; i ++)
    {
        if(a[i].first != a[i - 1].first)
            j = i;
        o[a[i].second] = j;
    }

    for(i = 1; i <= n; i ++)
        printf("%d ", o[i]);
    putchar('\n');

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
using namespace std;

typedef pair<int, int> pii;

pii a[N];

int main(void)
{
    int n, m;
    int i;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i].first);
        a[i].first = (a[i].first - 1) / m + 1;
        a[i].second = i;
    }

    sort(a + 1, a + n + 1, greater<pii>());
    printf("%d\n", a[1].second);

    return 0;
}
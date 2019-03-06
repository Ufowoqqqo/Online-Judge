#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#define N 100020
#define M 100020
using namespace std;

int a[N], o[M];
pair<int, int> l[M];

int main(void)
{
    int n, m;
    int i, j;
    set<int> s;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    for(i = 1; i <= m; i ++)
    {
        scanf("%d", &l[i].first);
        l[i].second = i;
    }
    sort(l + 1, l + m + 1);
    reverse(l + 1, l + m + 1);

    s.clear();
    for(i = 1, j = n; i <= m; i ++)
    {
        for(; l[i].first <= j; j --)
            s.insert(a[j]);
        o[l[i].second] = s.size();
    }

    for(i = 1; i <= m; i ++)
        printf("%d\n", o[i]);

    return 0;
}
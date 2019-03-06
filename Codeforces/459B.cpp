#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#define INF 1000000001
using namespace std;

int main(void)
{
    int n;
    int x, y;
    int i;
    int m;
    multiset<int> s;

    scanf("%d", &n);
    s.clear();
    for(i = y = 0, x = INF; i < n; i ++)
    {
        scanf("%d", &m);
        x = min(x, m);
        y = max(y, m);
        s.insert(m);
    }

    printf("%d %I64d\n", y - x, x != y ? (long long)s.count(x) * (long long)s.count(y) : ((long long)n * (long long)(n - 1)) >> 1);

    return 0;
}
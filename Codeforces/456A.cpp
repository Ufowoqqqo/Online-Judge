#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
using namespace std;

pair<int, int> a[N];

int main(void)
{
    int n, m;
    int i;
    bool o;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d %d", &a[i].first, &a[i].second);
    sort(a, a + n);

    for(i = m = 0, o = false; i < n; m = max(m, a[i ++].second))
        o |= a[i].second < m;
    puts(o ? "Happy Alex" : "Poor Alex");

    return 0;
}
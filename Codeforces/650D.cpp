#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define N 400020
#define M 400020
using namespace std;

int n, h[N], f[M], g[M], t[N + M], p[N], a[N], b[N], o[M];
pair<int, pair<int, int> > q[M];

inline int lowBit(int x)
{
    return x & -x;
}

void update(int p, int v)
{
    int i;

    for(i = p; i <= n; i += lowBit(i))
        t[i] = max(t[i], v);

    return;
}

int query(int p)
{
    int o, i;

    for(o = 0, i = p; i; i -= lowBit(i))
        o = max(o, t[i]);

    return o;
}

int main(void)
{
    int n, m;
    int u;
    int i, j;
    vector<int> v;

    // freopen("t.in" , "r", stdin );

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &h[i]);
        v.push_back(h[i]);
    }

    for(i = 0; i < m; i ++)
    {
        scanf("%d %d", &q[i].first, &q[i].second.first);
        v.push_back(q[i].second.first);
        q[i].second.second = i;
        o[i] = 1;
    }
    sort(q, q + m);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ::n = v.size();
    for(i = 1; i <= n; i ++)
        h[i] = lower_bound(v.begin(), v.end(), h[i]) - v.begin() + 1;

    memset(t, 0, sizeof t);
    for(i = 1, u = 0; i <= n; i ++)
    {
        f[i] = query(h[i] - 1) + 1;
        u = max(u, f[i]);
        update(h[i], f[i]);
    }

    memset(t, 0, sizeof t);
    for(i = n; i; i --)
    {
        g[i] = query(v.size() - h[i]) + 1;
        update(v.size() - h[i] + 1, g[i]);
    }

    for(i = 1; i <= n; i ++)
        if(f[i] + g[i] == u + 1)
            ++ p[f[i]];

    for(i = 0; i < m; i ++)
        q[i].second.first = lower_bound(v.begin(), v.end(), q[i].second.first) - v.begin() + 1;

    memset(t, 0, sizeof t);
    for(i = 1, j = 0; i <= n; i ++)
    {
        for(; j < m && q[j].first == i; j ++)
            o[q[j].second.second] += query(q[j].second.first - 1);
        update(h[i], query(h[i] - 1) + 1);
    }

    memset(t, 0, sizeof t);
    for(i = n, j = m - 1; i; i --)
    {
        for(; 0 <= j && q[j].first == i; j --)
            o[q[j].second.second] += query(v.size() - q[j].second.first);
        update(v.size() - h[i] + 1, query(v.size() - h[i]) + 1);
    }

    for(i = 0; i < m; i ++)
        o[q[i].second.second] = max(o[q[i].second.second], u - (f[q[i].first] + g[q[i].first] == u + 1 && p[f[q[i].first]] == 1));

    for(i = 0; i < m; i ++)
        printf("%d\n", o[i]);

    return 0;
}
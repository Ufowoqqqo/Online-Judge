#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define N 120
#define INF 1000000001
using namespace std;

class MaximumFlow
{
public:
    class Edge
    {
    public:
        int v, c, p;
    };
    vector<Edge> e[N << 1];
    int s, t;
    MaximumFlow(void) : s(0), t(0)
    {
        int i;

        for(i = 0; i < (N << 1); i ++)
            e[i].clear();

        return;
    }

    void addEdge(int u, int v, int w)
    {
        int x, y;

        x = e[u].size();
        y = e[v].size();
        e[u].push_back((Edge){v, w, y});
        e[v].push_back((Edge){u, 0, x});

        return;
    }

    int c[N << 1], d[N << 1];

    bool bfs(void)
    {
        queue<int> q;
        int x, i;

        for(; !q.empty(); q.pop())
            ;
        memset(c, 0, sizeof c);
        memset(d, 0, sizeof d);

        for(q.push(s), d[s] = 1; !q.empty(); )
        {
            x = q.front();
            q.pop();

            for(i = 0; i < (signed)e[x].size(); i ++)
                if(e[x].at(i).c && !d[e[x].at(i).v])
                {
                    d[e[x].at(i).v] = d[x] + 1;
                    q.push(e[x].at(i).v);
                }
        }

        return !!d[t];
    }

    int dfs(int x, int f)
    {
        int o;
        int p;

        if(x == t)
            return f;
        for(o = 0; c[x] < (signed)e[x].size(); c[x] ++)
            if(e[x].at(c[x]).c && d[x] + 1 == d[e[x].at(c[x]).v])
            {
                p = dfs(e[x].at(c[x]).v, min(f, e[x].at(c[x]).c));
                o += p;
                f -= p;
                e[x].at(c[x]).c -= p;
                e[e[x].at(c[x]).v].at(e[x].at(c[x]).p).c += p;
                if(!f)
                    break;
            }

        return o;
    }

    int solve(void)
    {
        int o;

        for(o = 0; bfs(); o += dfs(s, INF))
            ;

        return o;
    }
} g;

int a[N], b[N];

int main(void)
{
    int n, m;
    int i, j;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(i = 1; i <= m; i ++)
        scanf("%d", &b[i]);

    for(g.s = 0, g.t = n + m + 1, i = 1; i <= n; i ++)
        g.addEdge(g.s, i, 1);
    for(i = 1; i <= m; i ++)
        g.addEdge(n + i, g.t, 1);

    for(i = 1; i <= n; i ++)
        for(j = 1; j <= m; j ++)
            if(abs(a[i] - b[j]) <= 1)
                g.addEdge(i, n + j, 1);

    printf("%d\n", g.solve());

    return 0;
}
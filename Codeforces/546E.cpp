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
    int s, t;
    vector<Edge> e[N << 1];

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
        int o, p;

        if(x == t)
            return f;

        for(o = 0; c[x] < (signed)e[x].size(); c[x] ++)
            if(e[x].at(c[x]).c && d[x] + 1 == d[e[x].at(c[x]).v])
            {
                p = dfs(e[x].at(c[x]).v, min(f, e[x].at(c[x]).c));
                e[x].at(c[x]).c -= p;
                e[e[x].at(c[x]).v].at(e[x].at(c[x]).p).c += p;
                o += p;
                f -= p;
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

int a[N], b[N], o[N][N];

int main(void)
{
    int n, m;
    int i, j;
    int x, y, p, q;

    // freopen("t.in" , "r", stdin );

    scanf("%d %d", &n, &m);
    for(i = 1, x = 0; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        x += a[i];
    }
    for(i = 1, y = 0; i <= n; i ++)
    {
        scanf("%d", &b[i]);
        y += b[i];
    }
    if(x ^ y)
    {
        puts("NO");

        return 0;
    }

    g.s = 0;
    g.t = (n << 1) + 1;
    for(i = 1; i <= n; i ++)
    {
        g.addEdge(g.s, i, a[i]);
        g.addEdge(i, n + i, INF);
        g.addEdge(n + i, g.t, b[i]);
    }

    for(i = 0; i < m; i ++)
    {
        scanf("%d %d", &p, &q);
        g.addEdge(p, n + q, INF);
        g.addEdge(q, n + p, INF);
    }
    if(g.solve() != x)
        puts("NO");
    else
    {
        puts("YES");
        for(i = 1; i <= n; i ++)
            for(j = 0; j < (signed)g.e[i].size(); j ++)
                if(i < g.e[i].at(j).v)
                    o[i][g.e[i].at(j).v - n] = g.e[g.e[i].at(j).v].at(g.e[i].at(j).p).c;
        for(i = 1; i <= n; i ++)
        {
            for(j = 1; j <= n; j ++)
                printf("%d ", o[i][j]);
            putchar('\n');
        }
    }

    return 0;
}
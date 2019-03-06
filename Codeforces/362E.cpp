#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define N 100
#define INF 0x1f1f1f1f1f1f1f1fLL
using namespace std;

long long k;

class MinimumCostMaximumFlow
{
public:
    class Edge
    {
    public:
        int v;
        long long c, w;
        int p;
    };
    int s, t;
    vector<Edge> e[N << 1];

    MinimumCostMaximumFlow(void) : s(0), t(0)
    {
        int i;

        for(i = 0; i < (N << 1); i ++)
            e[i].clear();

        return;
    }

    void addEdge(int u, int v, long long c, long long w)
    {
        int x, y;

        // printf("addEdge(u = %d, v=  %d, c = %I64d, w = %I64d)\n", u, v, c, w);

        x = e[u].size();
        y = e[v].size();
        e[u].push_back((Edge){v, c,  w, y});
        e[v].push_back((Edge){u, 0, -w, x});

        return;
    }

    long long d[N << 1], f[N << 1];
    int p[N << 1];

    bool spfa(void)
    {
        queue<int> q;
        int x, i;

        memset(d, 0x1f, sizeof d);
        for(d[s] = 0, f[s] = INF, q.push(s); !q.empty(); )
        {
            x = q.front();
            q.pop();

            // printf("d[%d] = %d\n", x, d[x]);

            for(i = 0; i < (signed)e[x].size(); i ++)
            	if(e[x].at(i).c && d[x] + e[x].at(i).w < d[e[x].at(i).v])
            	{
            		// printf("%d -> %d, c = %d, w = %d\n", x, e[x].at(i).v, e[x].at(i).c, e[x].at(i).w);
            		d[e[x].at(i).v] = d[x] + e[x].at(i).w;
            		f[e[x].at(i).v] = min(f[x], e[x].at(i).c);
            		p[e[x].at(i).v] = e[x].at(i).p;
            		q.push(e[x].at(i).v);
            	}
        }

        // printf("d[t] = %I64d, %I64d\n", d[t], INF);

        return d[t] != INF;
    }

    long long x, y;

    long long solve()
    {
    	int z;

        for(x = y = 0; spfa() && y + d[t] * f[t] <= k; x += f[t], y += d[t] * f[t])
        {
        	// printf("x = %I64d, y = %I64d, d[t] = %I64d, f[t] = %I64d\n", x, y, d[t], f[t]);
        	for(z = t; z != s; z = e[z].at(p[z]).v)
        	{
        		e[z].at(p[z]).c += f[t];
        		e[e[z].at(p[z]).v].at(e[z].at(p[z]).p).c -= f[t];
        	}
        }

        // printf("x = %I64d, y = %I64d, d[t] = %I64d, f[t] = %I64d\n", x, y, d[t], f[t]);

        return d[t] ? x + (k - y) / d[t] : x;
    }
} g;

int main(void)
{
    int n;
    int i, j;
    long long c;

    // freopen("t.in" , "r", stdin );
    // freopen("t.out", "w", stdout);

    scanf("%d %I64d", &n, &k);
    for(i = g.s = 1, g.t = n; i <= n; i ++)
        for(j = 1; j <= n; j ++)
        {
            scanf("%I64d", &c);
            if(i == j)
                continue;
            if(c)
            {
            	g.addEdge(i, j,   c, 0);
            	g.addEdge(i, j, INF, 1);
            }
        }

    printf("%I64d\n", g.solve());

    return 0;
}
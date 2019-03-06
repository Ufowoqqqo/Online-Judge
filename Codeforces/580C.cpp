#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define N 100020
using namespace std;

int m, o, a[N];
vector<int> e[N];

void dfs(int x, int p, int s, int w)
{
    int i;

    if((signed)e[x].size() == 1 && x != 1)
        o += max(w, s) <= m;

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x].at(i) != p)
            if(a[e[x].at(i)])
                dfs(e[x].at(i), x, s + 1, w);
            else
                dfs(e[x].at(i), x, 0, max(w, s));

    return;
}

int main(void)
{
    int n;
    int i;
    int u, v;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1, 0, a[1], a[1]);
    printf("%d\n", o);

    return 0;
}
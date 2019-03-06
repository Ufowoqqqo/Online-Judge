#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define N 2020
using namespace std;

int p[N], d[N], o;
vector<int> e[N];

void dfs(int x)
{
    int i;

    o = max(o, d[x]);
    for(i = 0; i < (signed)e[x].size(); i ++)
    {
        d[e[x].at(i)] = d[x] + 1;
        dfs(e[x].at(i));
    }

    return;
}

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &p[i]);
        if(p[i] == -1)
            p[i] = 0;
        e[p[i]].push_back(i);
    }

    dfs(0);
    printf("%d\n", o);

    return 0;
}
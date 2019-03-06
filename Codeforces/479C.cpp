#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define N 50020
using namespace std;

int a[N], b[N], c[N];
vector<int> e[N];
bool f[N];

bool cmp(int x, int y)
{
    return a[x] < a[y];
}

int main(void)
{
    int n;
    int i, j, k;
    int o;
    vector<int> v;

    scanf("%d", &n);
    v.clear();
    for(i = 0; i < n; i ++)
    {
        scanf("%d %d", &a[i], &b[i]);
        v.push_back(a[i]);
        v.push_back(b[i]);
        c[i] = a[i];
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(i = 0; i < n; i ++)
    {
        e[lower_bound(v.begin(), v.end(), a[i]) - v.begin()].push_back(i);
        e[lower_bound(v.begin(), v.end(), b[i]) - v.begin()].push_back(i);
    }

    sort(c, c + n);
    for(i = k = o = 0; i < (signed)v.size(); i ++)
    {
        sort(e[i].begin(), e[i].end(), cmp);
        for(j = 0; j < (signed)e[i].size(); j ++)
            if(!f[e[i].at(j)] && a[e[i].at(j)] == c[k])
            {
                f[e[i].at(j)] = true;
                o = v.at(i);
                ++ k;
            }
    }

    printf("%d\n", o);

    return 0;
}
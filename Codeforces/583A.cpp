#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 500
using namespace std;

int h[N * N], v[N * N];
bool r[N], c[N];

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);
    for(i = 1; i <= n * n; i ++)
    {
        scanf("%d %d", &h[i], &v[i]);
        if(!r[h[i]] && !c[v[i]])
        {
            r[h[i]] = c[v[i]] = true;
            printf("%d ", i);
        }
    }

    return 0;
}
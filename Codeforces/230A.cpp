#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1020
using namespace std;

int x[N], y[N];
bool v[N];

bool solve(int s, int n)
{
    int i, j, k;

    for(i = 0; i < n; i ++)
    {
        for(j = 0, k = -1; j < n; j ++)
            if(!v[j] && x[j] < s && (k == -1 || y[k] < y[j]))
                k = j;
        if(k == -1)
            return false;

        v[k] = true;
        s += y[k];
    }

    return true;
}

int main(void)
{
    int s, n;
    int i;

    scanf("%d %d", &s, &n);
    for(i = 0; i < n; i ++)
        scanf("%d %d", &x[i], &y[i]);

    puts(solve(s, n) ? "YES" : "NO");

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 30020
using namespace std;

int a[N];

bool solve(int n, int t)
{
    int i;

    for(i = 1; i < n; i += a[i])
        if(i == t)
            return true;

    return t == n;
}

int main(void)
{
    int n, t;
    int i;

    scanf("%d %d", &n, &t);
    for(i = 1; i < n; i ++)
        scanf("%d", &a[i]);

    puts(solve(n, t) ? "YES" : "NO");

    return 0;
}
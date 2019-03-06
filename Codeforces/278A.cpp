#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
using namespace std;

int d[N];

int main(void)
{
    int n;
    int i;
    int s, t;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &d[i]);
        d[i] += d[i - 1];
    }

    scanf("%d %d", &s, &t);
    if(t < s)
        swap(s, t);
    printf("%d\n", min(d[t - 1] - d[s - 1], d[n] - (d[t - 1] - d[s - 1])));

    return 0;
}
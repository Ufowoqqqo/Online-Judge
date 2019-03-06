#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 120
using namespace std;

int t[N];

int main(void)
{
    int n, d;
    int i;
    int s;

    scanf("%d %d", &n, &d);
    for(i = s = 0; i < n; i ++)
    {
        scanf("%d", &t[i]);
        s += t[i];
    }

    if(d < (n - 1) * 10 + s)
        puts("-1");
    else
        printf("%d\n", ((n - 1) << 1) + (d - ((n - 1) * 10 + s)) / 5);

    return 0;
}
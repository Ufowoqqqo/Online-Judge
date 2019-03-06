#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 10000
using namespace std;

int a[N];

int main(void)
{
    int n;
    int i;
    int t, o;

    scanf("%d", &n);
    for(i = o = 0, t = -1; i < n; i ++)
    {
        scanf("%d", &a[i]);
        if(a[i])
        {
            o += t == -1 ? 1 : min(i - t, 2);
            t = i;
        }
    }

    printf("%d\n", o);

    return 0;
}
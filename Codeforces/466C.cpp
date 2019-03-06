#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 500020
using namespace std;

long long a[N];

int main(void)
{
    int n;
    int i;
    long long s, t;
    long long m, o;

    scanf("%d", &n);
    for(i = s = 0; i < n; i ++)
    {
        scanf("%I64d", &a[i]);
        s += a[i];
    }

    if(s % 3)
        puts("0");
    else
    {
        for(i = t = m = o = 0; i + 1 < n; i ++)
        {
            t += a[i];
            if(t * 3 == (s << 1))
                o += m;
            if(t * 3 ==  s      )
                ++ m;
        }
        printf("%I64d\n", o);
    }

    return 0;
}
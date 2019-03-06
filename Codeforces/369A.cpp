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
    int n, m, k;
    int i;
    int o;

    scanf("%d %d %d", &n, &m, &k);
    for(i = 1, o = 0; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        if(a[i] == 1)
            if(m)
                -- m;
            else
                ++ o;
        if(a[i] == 2)
            if(k)
                -- k;
            else
                if(m)
                    -- m;
                else
                    ++ o;
    }

    printf("%d\n", o);

    return 0;
}
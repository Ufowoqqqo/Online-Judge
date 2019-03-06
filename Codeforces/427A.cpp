#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int o;
    int i, j;
    int x;

    scanf("%d", &n);
    for(o = i = j = 0; i < n; i ++)
    {
        scanf("%d", &x);
        if(x == -1)
            if(j)
                -- j;
            else
                ++ o;
        else
            j += x;
    }
    printf("%d\n", o);

    return 0;
}
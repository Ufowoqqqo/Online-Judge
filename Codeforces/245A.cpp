#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int i;
    int t, x, y;
    int a, b, c, d;

    scanf("%d", &n);
    for(i = a = b = c = d = 0; i < n; i ++)
    {
        scanf("%d %d %d", &t, &x, &y);
        if(t == 1)
        {
            a += x;
            b += y;
        }
        if(t == 2)
        {
            c += x;
            d += y;
        }
    }

    puts(b <= a ? "LIVE" : "DEAD");
    puts(d <= c ? "LIVE" : "DEAD");

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1020
using namespace std;

char s[N], t[N];

int main(void)
{
    int n;
    int i;
    int o;
    int x, y;

    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    for(i = o = 0; i < n; i ++)
    {
        x = s[i] - '0';
        y = t[i] - '0';
        if(y < x)
            swap(x, y);
        o += min(y - x, 10 - (y - x));
    }

    printf("%d\n", o);

    return 0;
}
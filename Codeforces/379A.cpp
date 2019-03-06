#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int a, b;
    int o;

    scanf("%d %d", &a, &b);
    for(o = 0; a >= b; )
    {
        o += b;
        a -= b;
        ++ a;
    }

    printf("%d\n", o + a);

    return 0;
}
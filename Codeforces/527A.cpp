#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    long long a, b;
    long long o;

    scanf("%I64d %I64d", &a, &b);

    for(o = 0; a % b; )
    {
        o += a / b;
        a %= b;
        if(a < b)
            swap(a, b);
    }

    printf("%I64d\n", o + a / b);

    return 0;
}
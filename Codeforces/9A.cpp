#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

inline int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

int main(void)
{
    int y, w;
    int d, g;

    scanf("%d %d", &y, &w);

    d = 6 - max(y, w) + 1;
    g = gcd(d, 6);

    printf("%d/%d\n", d / g, 6 / g);

    return 0;
}
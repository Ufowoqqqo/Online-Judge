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
    int a, b, n;
    int i;

    scanf("%d %d %d", &a, &b, &n);
    for(i = 0; n; i ^= 1)
        n -= gcd(i ? b : a, n);
    printf("%d\n", i ^ 1);

    return 0;
}
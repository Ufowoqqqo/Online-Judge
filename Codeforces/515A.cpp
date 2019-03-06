#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int a, b, s, t;

    scanf("%d %d %d", &a, &b, &s);
    t = abs(a) + abs(b);

    puts(t <= s && ((t) & 1) == (s & 1) ? "Yes" : "No");

    return 0;
}
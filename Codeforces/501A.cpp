#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c, d;
    double m, v;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    m = max(a * 3.0 / 10.0, a - a / 250.0 * c);
    v = max(b * 3.0 / 10.0, b - b / 250.0 * d);

    if(v < m)
        puts("Misha");
    if(m < v)
        puts("Vasya");
    if(m == v)
        puts("Tie");

    return 0;
}
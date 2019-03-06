#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n, m, a, b;
    int o;
    int i;

    scanf("%d %d %d %d", &n, &m, &a, &b);
    for(o = n * a, i = 0; i < n; i ++)
        o = min(o, i * a + ((n - i - 1) / m + 1) * b);
    printf("%d\n", o);

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void print(int x, int y)
{
    int i;

    for(i = y; i < x; i ++)
        putchar('*');
    for(i = 0; i < y; i ++)
        putchar('D');
    putchar('D');
    for(i = 0; i < y; i ++)
        putchar('D');
    for(i = y; i < x; i ++)
        putchar('*');
    putchar('\n');

    return;
}

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);

    for(i = 0, n >>= 1; i < n; i ++)
        print(n, i);
    print(n, n);
    for(i = n - 1; i >= 0; i --)
        print(n, i);

    return 0;
}
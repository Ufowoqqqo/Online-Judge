#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void print(int n, int m)
{
    int i;

    for(i = 0; i < ((n - m) << 1); i ++)
        putchar(' ');

    for(i = 0; i < m; i ++)
        printf("%d ", i);
    printf("%d", m);
    for(i = m - 1; i >= 0; i --)
        printf(" %d", i);

    putchar('\n');

    return;
}

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);

    for(i = 0; i < n; i ++)
        print(n, i);
    print(n, n);
    for(i = n - 1; i >= 0; i --)
        print(n, i);

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int a[2], o[2];

int main(void)
{
    int n;
    int i;
    int x;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &x);
        ++ a[x & 1];
        o[x & 1] = i;
    }

    printf("%d\n", a[0] == 1 ? o[0] : o[1]);

    return 0;
}
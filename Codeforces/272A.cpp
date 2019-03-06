#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
using namespace std;

int a[N];

int main(void)
{
    int n;
    int i;
    int s, o;

    scanf("%d", &n);
    for(i = s = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        s += a[i];
    }

    for(i = 1, o = 0; i <= 5; i ++)
        o += (s + i) % (n + 1) != 1;
    printf("%d\n", o);

    return 0;
}
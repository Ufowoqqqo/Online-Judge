#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100
using namespace std;

int a[N], c[10];

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        c[i % 3] += a[i];
    }

    if(c[1] < c[0] && c[2] < c[0])
        puts("back");
    if(c[0] < c[1] && c[2] < c[1])
        puts("chest");
    if(c[0] < c[2] && c[1] < c[2])
        puts("biceps");

    return 0;
}
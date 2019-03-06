#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
using namespace std;

int a[N], b[N];

int main(void)
{
    int nA, nB;
    int k, m;
    int i;

    scanf("%d %d", &nA, &nB);
    scanf("%d %d", &k, &m);
    for(i = 1; i <= nA; i ++)
        scanf("%d", &a[i]);
    for(i = 1; i <= nB; i ++)
        scanf("%d", &b[i]);

    puts(a[k] < b[nB - m + 1] ? "YES" : "NO");

    return 0;
}
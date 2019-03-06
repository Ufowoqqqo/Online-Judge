#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 200020
using namespace std;

char s[N];
int c[1 << 8];

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);
    scanf("%s", s);
    for(i = 0; i < n; i ++)
        ++ c[s[i]];

    printf("%d\n", abs(c['0'] - c['1']));

    return 0;
}
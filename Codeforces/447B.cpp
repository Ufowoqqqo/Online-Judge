#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 10000
using namespace std;

char s[N];
int w[1 << 8];

int main(void)
{
    int k;
    int i;
    int m, n, o;

    scanf("%s", s + 1);
    scanf("%d", &k);
    for(i = 'a', m = 0; i <= 'z'; i ++)
    {
        scanf("%d", &w[i]);
        m = max(m, w[i]);
    }

    n = strlen(s + 1);
    for(i = 1, o = 0; i <= n + k; i ++)
        o += i * (i <= n ? w[s[i]] : m);

    printf("%d\n", o);
    
    return 0;
}
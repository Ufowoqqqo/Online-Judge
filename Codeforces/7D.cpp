#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 5000020
#define BASE 137731735
#define G 1000000007
using namespace std;

char s[N];
__int64 f[N], g[N], h[N], p;

inline int idx(char c)
{
    return isdigit(c) ? c - '0' : (isupper(c) ? c - 'A' + 10 : c - 'a' + 36);
}

int main(void)
{
    int n;
    int i;
    __int64 o;

    gets(s + 1);
    n = strlen(s + 1);

    for(i =     1; i <= n; i ++           )
        g[i] = (g[i - 1] * BASE % G + idx(s[i])) % G;
    for(i = p = 1; i <= n; i ++, (p *= BASE) %= G)
        h[i] = (idx(s[i]) * p % G + h[i - 1]) % G;

    for(i = 1, o = 0; i <= n; i ++)
        if(g[i] == h[i])
            o += (f[i] = f[i >> 1] + 1);
    cout << o << endl;

    return 0;
}
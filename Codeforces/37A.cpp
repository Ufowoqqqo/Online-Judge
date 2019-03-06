#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#define N 1020
using namespace std;

int l[N];

int main(void)
{
    int n;
    int i;
    int o;
    map<int, int> s;

    scanf("%d", &n);
    s.clear();
    for(i = o = 0; i < n; i ++)
    {
        scanf("%d", &l[i]);
        o = max(o, ++ s[l[i]]);
    }

    printf("%d %d\n", o, (signed)s.size());

    return 0;
}
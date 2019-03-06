#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    int n;
    int i;
    int h, m;
    int o;
    map<pair<int, int>, int> s;

    scanf("%d", &n);
    for(i = o = 0; i < n; i ++)
    {
        scanf("%d %d", &h, &m);
        o = max(o, ++ s[make_pair(h, m)]);
    }

    printf("%d\n", o);

    return 0;
}
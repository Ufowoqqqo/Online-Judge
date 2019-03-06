#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#define N 100020
using namespace std;

int t[N];

int main(void)
{
    int n;
    int i;
    long long w;
    int o;
    multiset<int> s;
    multiset<int>::iterator p;

    scanf("%d", &n);
    s.clear();
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &t[i]);
        s.insert(t[i]);
    }

    for(i = w = o = 0; i < n; i ++)
    {
        p = s.lower_bound(w);
        if(p == s.end())
            break;
        else
        {
            ++ o;
            w += *p;
            s.erase(p);
        }
    }
    printf("%d\n", o);

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    int i;
    int x, o;
    vector<int> v[5];

    for(i = 0; i < 5; i ++)
        v[i].clear();

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &x);
        v[x].push_back(i);
    }

    printf("%d\n", o = min(v[1].size(), min(v[2].size(), v[3].size())));
    for(i = 0; i < o; i ++)
        printf("%d %d %d\n", v[1].at(i), v[2].at(i), v[3].at(i));

    return 0;
}
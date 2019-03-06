#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define N 500
using namespace std;

int k[N], s[N][N];

int main(void)
{
    int n, v;
    int i, j;
    int t;
    vector<int> o;

    scanf("%d %d", &n, &v);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &k[i]);
        for(j = 0; j < k[i]; j ++)
            scanf("%d", &s[i][j]);

        for(j = 1, t = s[i][0]; j < k[i]; j ++)
            t = min(t, s[i][j]);
        if(t < v)
            o.push_back(i);
    }

    printf("%d\n", o.size());
    for(i = 0; i < (signed)o.size(); i ++)
        printf("%d ", o.at(i));

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define N 1000
using namespace std;

int A[N][N];
bool g[N];

int main(void)
{
    int n;
    int i, j;
    vector<int> o;

    scanf("%d", &n);
    memset(g, true, sizeof g);
    for(i = 1; i <= n; i ++)
    {
        for(j = 1; j <= n; j ++)
            scanf("%d", &A[i][j]);
        for(j = i + 1; j <= n; j ++)
        {
            if(A[i][j] == 1)
                g[i] = false;
            if(A[i][j] == 2)
                g[j] = false;
            if(A[i][j] == 3)
                g[i] = g[j] = false;
        }
    }

    o.clear();
    for(i = 1; i <= n; i ++)
        if(g[i])
            o.push_back(i);

    printf("%u\n", o.size());
    for(i = 0; i < (signed)o.size(); i ++)
        printf("%d ", o.at(i));

    return 0;
}
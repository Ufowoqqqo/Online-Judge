#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define N 1000020
using namespace std;

int p[N];

int main(void)
{
    int n;
    int i, j;
    vector<int> v;

    scanf("%d", &n);
    v.clear();
    for(i = 2; i <= n; i ++)
    {
        if(!p[i])
        {
            p[i] = i;
            v.push_back(i);
        }

        for(j = 0; j < (signed)v.size() && i * v.at(j) <= n && v.at(j) <= p[i]; j ++)
            p[i * v.at(j)] = v.at(j);
    }

    for(i = 4; i <= n; i ++)
        if(p[i] != i && p[n - i] + i != n)
        {
            printf("%d %d\n", i, n - i);
            break;
        }

    return 0;
}
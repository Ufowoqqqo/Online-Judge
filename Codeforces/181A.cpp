#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define N 1000
using namespace std;

char s[N][N];

int main(void)
{
    int n, m;
    int i, j;
    vector<pair<int, int> > v;

    scanf("%d %d", &n, &m);
    v.clear();
    for(i = 1; i <= n; i ++)
    {
        scanf("%s", s[i] + 1);
        for(j = 1; j <= m; j ++)
            if(s[i][j] == '*')
                v.push_back(make_pair(i, j));
    }

    if(v.at(0).first == v.at(1).first)
        printf("%d ", v.at(2).first);
    if(v.at(0).first == v.at(2).first)
        printf("%d ", v.at(1).first);
    if(v.at(1).first == v.at(2).first)
        printf("%d ", v.at(0).first);

    if(v.at(0).second == v.at(1).second)
        printf("%d\n", v.at(2).second);
    if(v.at(0).second == v.at(2).second)
        printf("%d\n", v.at(1).second);
    if(v.at(1).second == v.at(2).second)
        printf("%d\n", v.at(0).second);

    return 0;
}
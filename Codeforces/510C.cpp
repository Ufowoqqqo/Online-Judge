#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#define N 120
#define L 120
using namespace std;

int d[1 << 8];
bool v[1 << 8], e[1 << 8][1 << 8];
char s[N][L];

bool dfs(int x, int k)
{
    char i;

    if(v[x])
        if(x == k)
            return false;
        else
            return true;
    v[x] = true;

    for(i = 'a'; i <= 'z'; i ++)
        if(e[x][i] && !dfs(i, k))
            return false;

    return true;
}

int main(void)
{
    int n;
    int i, j;
    queue<char> q;
    char x;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%s", s[i]);

    for(i = 1; i < n; i ++)
    {
        for(j = 0; s[i - 1][j] && s[i][j]; j ++)
            if(s[i - 1][j] != s[i][j])
            {
                e[s[i - 1][j]][s[i][j]] = true;

                break;
            }
        if(s[i - 1][j] && !s[i][j])
        {
            puts("Impossible");

            return 0;
        }
    }

    for(i = 'a'; i <= 'z'; i ++)
        for(j = 'a'; j <= 'z'; j ++)
            d[i] += e[j][i];

    for(; !q.empty(); q.pop())
        ;
    for(i = 'a'; i <= 'z'; i ++)
    {
        memset(v, false, sizeof v);
        if(!dfs(i, i))
        {
            puts("Impossible");

            return 0;
        }
        else
            if(!d[i])
                q.push(i);
    }

    if(q.empty())
    {
        puts("Impossible");

        return 0;
    }

    for(; !q.empty(); )
    {
        x = q.front();
        q.pop();
        putchar(x);

        for(i = 'a'; i <= 'z'; i ++)
            if(e[x][i] && !(-- d[i]))
                q.push(i);
    }
    putchar('\n');

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(void)
{
    int n, m;
    queue<int> q;
    map<int, int> s;
    int x;

    scanf("%d %d", &n, &m);

    for(; !q.empty(); q.pop())
        ;
    for(q.push(n), s[n] = 0; !q.empty(); )
    {
        x = q.front();
        q.pop();

        // printf("%d %d\n", x, s[x]);

        if((x << 1) == m)
        {
            printf("%d\n", s[x] + 1);

            break;
        }
        if((x << 1) <= (m << 1) && (!s.count(x << 1) || s[x] + 1 < s[x << 1]))
        {
            s[x << 1] = s[x] + 1;
            q.push(x << 1);
        }

        if(x == m + 1)
        {
            printf("%d\n", s[x] + 1);

            break;
        }
        if(!s.count(x - 1) || s[x] + 1 < s[x - 1])
        {
            s[x - 1] = s[x] + 1;
            q.push(x - 1);
        }
    }

    return 0;
}
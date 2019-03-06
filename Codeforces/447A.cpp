#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define P 3000
#define N 3000
using namespace std;

int x[N];
bool h[P];

int main(void)
{
    int p, n;
    int i;

    scanf("%d %d", &p, &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &x[i]);
        x[i] %= p;
        if(h[x[i]])
        {
            printf("%d\n", i);

            return 0;
        }
        h[x[i]] = true;
    }

    puts("-1");

    return 0;
}
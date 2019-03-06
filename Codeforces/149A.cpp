#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 12
using namespace std;

int a[N];

int main(void)
{
    int k;
    int i;
    int s;

    scanf("%d", &k);
    for(i = 0; i < N; i ++)
        scanf("%d", &a[i]);

    if(!k)
    {
        puts("0");

        return 0;
    }

    sort(a, a + N, greater<int>());
    for(i = s = 0; i < N; i ++)
    {
        s += a[i];
        if(k <= s)
        {
            printf("%d\n", i + 1);

            return 0;
        }
    }

    puts("-1");

    return 0;
}
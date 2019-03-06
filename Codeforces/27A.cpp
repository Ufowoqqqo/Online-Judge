#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 3020
using namespace std;

int a[N];
bool b[N];

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        b[a[i]] = true;
    }

    for(i = 1; ; i ++)
        if(!b[i])
        {
            printf("%d\n", i);

            break;
        }

    return 0;
}
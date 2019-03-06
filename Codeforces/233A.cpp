#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);

    if(n & 1)
        puts("-1");
    else
        for(i = 1; i <= n; i ++)
            printf("%d ", i & 1 ? i + 1 : i - 1);

    return 0;
}
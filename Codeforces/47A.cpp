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
    for(i = 1, n <<= 1; i * (i + 1) <= n; i ++)
        if(i * (i + 1) == n)
        {
            puts("YES");

            return 0;
        }

    puts("NO");

    return 0;
}
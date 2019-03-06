#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int i, j, k;

    scanf("%d", &n);
    for(i = j = k = 1; ; k += (j += ++ i))
        if(k <= n && n < k + j + i + 1)
        {
            printf("%d\n", i);
            break;
        }

    return 0;
}
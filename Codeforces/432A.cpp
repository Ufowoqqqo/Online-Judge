#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n, k;
    int i;
    int x, y;

    scanf("%d %d", &n, &k);
    for(i = x = 0; i < n; i ++)
    {
        scanf("%d", &y);
        x += y + k <= 5;
    }
    printf("%d\n", x / 3);

    return 0;
}
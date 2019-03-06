#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int i, o;

    scanf("%d", &n);
    for(i = o = 1; i < n; i ++)
    {
        o += i;
        o = (o - 1) % n + 1;
        printf("%d ", o);
    }

    return 0;
}
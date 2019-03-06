#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 50
using namespace std;

int main(void)
{
    int n, s;
    int i;
    int p;

    scanf("%d", &n);
    for(i = s = 0; i < n; i ++)
    {
        scanf("%d", &p);
        s += p;
    }

    printf("%.4lf\n", (double)s / n);

    return 0;
}
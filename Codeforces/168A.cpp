#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n, x, y;

    scanf("%d %d %d", &n, &x, &y);

    printf("%d\n", max((int)ceil(n * y / 100.0) - x, 0));

    return 0;
}

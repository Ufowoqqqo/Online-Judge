#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int d1, d2, d3;

    scanf("%d %d %d", &d1, &d2, &d3);
    printf("%d\n", min(d1 + d2 + d3, min(d1 + d2, min(d1 + d3, d2 + d3)) << 1));

    return 0;
}
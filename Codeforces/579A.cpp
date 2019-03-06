#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int x;

    scanf("%d", &x);
    printf("%d\n", __builtin_popcount(x));

    return 0;
}
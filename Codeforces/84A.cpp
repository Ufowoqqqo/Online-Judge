#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n;

    scanf("%d", &n);

    printf("%d\n", (n * 3) >> 1);

    return 0;
}
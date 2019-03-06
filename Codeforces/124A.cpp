#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n, a, b;

    scanf("%d %d %d", &n, &a, &b);
    printf("%d\n", max(n - max(a + 1, n - b) + 1, 0));

    return 0;
}
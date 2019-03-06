#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n1, n2, k1, k2;

    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    puts(n1 <= n2 ? "Second" : "First");

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    long long n;

    scanf("%I64d", &n);
    printf("%I64d\n", n * (n * n + 5) / 6);

    return 0;
}
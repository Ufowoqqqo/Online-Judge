#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100
using namespace std;

char s[N];

int main(void)
{
    int n;

    scanf("%s", s);

    n = strlen(s);

    printf("%d\n", (n + 1) * 26 - n);

    return 0;
}
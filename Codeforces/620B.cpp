#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

inline int calc(int x)
{
    int o;

    for(o = 0; x / 10; x /= 10) {
        o += c[x % 10];
    }

    return o + c[x];
}

int main(void)
{
    int a, b;
    int i;
    int o;

    scanf("%d %d", &a, &b);

    for(i = a, o = 0; i <= b; i ++) {
        o += calc(i);
    }

    printf("%d\n", o);

    return 0;
}

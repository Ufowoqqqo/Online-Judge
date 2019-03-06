#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int a, b, c, x, y;

    scanf("%d %d %d", &a,&b, &c);
    x = a + b + c;
    scanf("%d %d %d", &a, &b, &c);
    y = a + b + c;

    scanf("%d", &n);

    puts((x + 4) / 5 + (y + 9) / 10 <= n ? "YES" : "NO");

    return 0;
}
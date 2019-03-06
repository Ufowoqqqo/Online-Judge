#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int x1, y1;
    int x2, y2;

    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);

    printf("%d\n", max(abs(x1 - x2), abs(y1 - y2)));

    return 0;
}
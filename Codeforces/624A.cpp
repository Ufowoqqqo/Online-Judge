#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int d, L, v1, v2;

    scanf("%d %d %d %d", &d, &L, &v1, &v2);

    printf("%.6lf\n", (double)(L - d) / (v1 + v2));

    return 0;
}
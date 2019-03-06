#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int l;
    int p, q;

    scanf("%d", &l);
    scanf("%d", &p);
    scanf("%d", &q);

    printf("%.4lf\n", l * p / (double)(p + q));

    return 0;
}
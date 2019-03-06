#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 6
using namespace std;

double m[N], w[N], x[N];

int main(void)
{
    int i;
    double hs, hu;
    double o;

    for(i = 1; i <= 5; i ++)
        scanf("%lf", &m[i]);
    for(i = 1; i <= 5; i ++)
        scanf("%lf", &w[i]);
    scanf("%lf %lf", &hs, &hu);

    for(i = 1, o = hs * 100.0 - hu * 50.0; i <= 5; i ++)
    {
        x[i] = 500.0 * i;
        o += max(0.3 * x[i], (1 - m[i] / 250.0) * x[i] - 50.0 * w[i]);
    }

    printf("%.0lf\n", o);

    return 0;
}
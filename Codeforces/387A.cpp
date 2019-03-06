#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int sh, sm;
    int th, tm;
    int oh, om;

    scanf("%d:%d", &sh, &sm);
    scanf("%d:%d", &th, &tm);

    om = sh * 60 + sm - (th * 60 + tm);
    if(om < 0)
        om += 1440;
    oh = om / 60;
    om %= 60;

    printf("%d%d:%d%d\n", oh / 10, oh % 10, om / 10, om % 10);

    return 0;
}
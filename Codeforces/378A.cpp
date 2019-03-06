#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int a, b;
    int i;
    int x, y, z;

    scanf("%d %d", &a, &b);
    for(i = 1, x = y = z = 0; i <= 6; i ++)
    {
        if(abs(i - a) <  abs(i - b))
            ++ x;
        if(abs(i - a) == abs(i - b))
            ++ y;
        if(abs(i - a) >  abs(i - b))
            ++ z;
    }

    printf("%d %d %d\n", x, y, z);

    return 0;
}
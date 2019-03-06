#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100
using namespace std;

int l[N], c[N];

int main(void)
{
    int i, j;

    for(i = 0; i < 6; i ++)
    {
        scanf("%d", &l[i]);
        ++ c[l[i]];
    }

    for(i = 1, j = 0; i <= 9; i ++)
        if(c[i] >= 4)
            j = i;
    if(!j)
        puts("Alien");
    else
    {
        c[j] -= 4;
        for(i = 1; i <= 9; i ++)
            if(c[i] == 2)
            {
                puts("Elephant");

                return 0;
            }
        puts("Bear");
    }

    return 0;
}
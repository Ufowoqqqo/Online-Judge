#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 120
using namespace std;

int x, y, z;
char s[N];

void output(int x, int y, int z)
{
    int i;

    for(i = 0; i < x; i ++)
        putchar('|');
    putchar('+');
    for(i = 0; i < y; i ++)
        putchar('|');
    putchar('=');
    for(i = 0; i < z; i ++)
        putchar('|');

    return;
}

bool solve(void)
{
    if(x + y == z)
    {
        output(x, y, z);
        return true;
    }
    if(x + y == z + 2)
    {
        if(x - 1)
            output(x - 1, y, z + 1);
        else
            output(x, y - 1, z + 1);
        return true;
    }
    if(x + y + 2 == z)
    {
        output(x + 1, y, z - 1);
        return true;
    }

    return false;
}

int main(void)
{
    scanf("%s", s);
    for(z = 0; s[z]; z ++)
    {
        if(s[z] == '+')
            x = z;
        if(s[z] == '=')
            y = z - x - 1;
    }
    z -= x + y + 2;

    if(!solve())
        puts("Impossible");

    return 0;
}
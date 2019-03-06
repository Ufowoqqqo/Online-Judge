#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 2000
using namespace std;

char s[N];

int main(void)
{
    int i;

    scanf("%s", s);

    for(i = 0; s[i]; i ++)
    {
        if(s[i] == '.')
            putchar('0');
        if(s[i] == '-')
        {
            putchar(s[i + 1] == '.' ? '1' : '2');
            ++ i;
        }
    }

    return 0;
}
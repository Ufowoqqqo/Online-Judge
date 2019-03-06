#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 500
using namespace std;

char s[N];

int main(void)
{
    int n;
    int i;
    int x, y;

    scanf("%d", &n);
    scanf("%s", s);

    for(i = 0; i < n; i ++)
        if(s[i] != '4' && s[i] != '7')
        {
            puts("NO");
            return 0;
        }

    for(i = x = 0; (i << 1) < n; i ++)
        x += s[i] - '0';
    for(i = (n >> 1), y = 0; i < n; i ++)
        y += s[i] - '0';

    puts(x == y ? "YES" : "NO");

    return 0;
}
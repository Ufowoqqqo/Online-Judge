#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

char s[20];

int transform(int p)
{
    int o;
    int i;

    for(o = 0, i = s[0] == '-'; s[i]; i ++)
        if(i ^ p)
            o = (o << 3) + (o << 1) + s[i] - '0';

    return o * (s[0] == '-' ? -1 : 1);
}

int main(void)
{
    int n;

    scanf("%s", s);
    n = strlen(s);

    printf("%d\n", max(transform(-1), max(transform(n - 2), transform(n - 1))));

    return 0;
}
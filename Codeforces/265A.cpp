#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100
using namespace std;

char s[N], t[N];

int main(void)
{
    int i;
    int o;

    scanf("%s", s + 1);
    scanf("%s", t + 1);

    for(i = o = 1; t[i]; i ++)
        if(s[o] == t[i])
            ++ o;

    printf("%d\n", o);

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100
using namespace std;

char f[N], m[N], s[N];

inline bool beat(char *s, char *t)
{
    return (!strcmp(s, "rock") && !strcmp(t, "scissors")) ||
           (!strcmp(s, "scissors") && !strcmp(t, "paper")) ||
           (!strcmp(s, "paper") && !strcmp(t, "rock"));
}

int main(void)
{
    char o;

    scanf("%s", f);
    scanf("%s", m);
    scanf("%s", s);

    o = '?';

    if(beat(f, m) && beat(f, s))
        o = 'F';
    if(beat(m, f) && beat(m, s))
        o = 'M';
    if(beat(s, f) && beat(s, m))
        o = 'S';

    putchar(o);

    return 0;
}
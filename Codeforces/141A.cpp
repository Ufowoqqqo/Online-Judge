#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define L 220
using namespace std;

char s[L], t[L];

int main(void)
{
    scanf("%s", s);
    scanf("%s", s + strlen(s));
    scanf("%s", t);

    sort(s, s + strlen(s));
    sort(t, t + strlen(s));

    puts(!strcmp(s, t) ? "YES" : "NO");

    return 0;
}
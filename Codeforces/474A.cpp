#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 120
using namespace std;

const char a[] = "qwertyuiop";
const char b[] = "asdfghjkl;";
const char c[] = "zxcvbnm,./";

char s[N];

char transform(char x, int d)
{
    int i;

    for(i = 0; i < 10; i ++)
        if(a[i] == x)
            return a[i + d];
    for(i = 0; i < 10; i ++)
        if(b[i] == x)
            return b[i + d];
    for(i = 0; i < 10; i ++)
        if(c[i] == x)
            return c[i + d];

    return 0;
}

int main(void)
{
    char d[2];
    int i;

    scanf("%s", d);
    scanf("%s", s);
    for(i = 0; s[i]; i ++)
        putchar(transform(s[i], d[0] == 'R' ? -1 : 1));
    putchar('\n');

    return 0;
}
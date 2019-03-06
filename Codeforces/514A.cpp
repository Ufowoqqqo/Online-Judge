#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100
using namespace std;

char s[N];

int main(void)
{
    int i;

    scanf("%s", s);
    for(i = 0; s[i]; i ++)
        putchar(i || s[i] != '9' ? min(s[i] - '0', 9 - s[i] + '0') + '0' : '9');
    putchar('\n');

    return 0;
}
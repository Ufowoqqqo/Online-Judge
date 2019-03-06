#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define L 100020
using namespace std;

int a[5];
char s[L];

int main(void)
{
    int i;
    int o;

    scanf("%d %d %d %d", &a[1], &a[2], &a[3], &a[4]);
    scanf("%s", s);

    for(i = o = 0; s[i]; o += a[s[i ++] - '0'])
        ;
    printf("%d\n", o);

    return 0;
}
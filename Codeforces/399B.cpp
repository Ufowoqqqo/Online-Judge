#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100
using namespace std;

int n;
char s[N];

int main(void)
{
    int n;
    unsigned long long o;
    int i;

    scanf("%d", &n);
    scanf("%s", s);

    for(o = i = 0; i < n; i ++)
        if(s[i] == 'B')
            o |= 1LL << i;
    printf("%I64d\n", o);

    return 0;
}
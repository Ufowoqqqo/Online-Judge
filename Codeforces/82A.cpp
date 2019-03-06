#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    long long n;
    long long i, j;
    int o;

    scanf("%I64d", &n);
    for(i = 1, j = 5; j < n; j += (i <<= 1) * 5)
        ;
    o = ((n - (j - 5 * i)) - 1) / i;

    if(o == 0)
        puts("Sheldon");
    if(o == 1)
        puts("Leonard");
    if(o == 2)
        puts("Penny");
    if(o == 3)
        puts("Rajesh");
    if(o == 4)
        puts("Howard");

    return 0;
}
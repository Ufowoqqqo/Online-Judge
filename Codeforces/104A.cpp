#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n;

    scanf("%d", &n);

    if(n <= 10 || n > 21)
        puts("0");
    if((11 <= n && n <= 19) || n == 21)
        puts("4");
    if(n == 20)
        puts("15");

    return 0;
}
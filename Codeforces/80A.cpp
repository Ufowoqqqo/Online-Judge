#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

bool isPrime(int x)
{
    int i;

    for(i = 2; i * i <= x; i ++)
        if(!(x % i))
            return false;

    return true;
}

int main(void)
{
    int n, m;
    int i;

    scanf("%d %d", &n, &m);

    for(i = n + 1; !isPrime(i); i ++)
        ;

    puts(i == m ? "YES" : "NO");

    return 0;
}
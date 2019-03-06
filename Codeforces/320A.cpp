#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

bool solve(int n)
{
    int i;

    for(i = 0; n; n /= 10)
    {
        if(n % 10 != 1 && n % 10 != 4)
            return false;
        if(n % 10 == 1)
            i = 0;
        else
            if(n == 4 || ++ i > 2)
                return false;
    }

    return true;
}

int main(void)
{
    int n;

    scanf("%d", &n);

    puts(solve(n) ? "YES" : "NO");

    return 0;
}
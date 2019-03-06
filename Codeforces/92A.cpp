#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n, m;
    int i;

    scanf("%d %d", &n, &m);
    for(i = 1; ; )
    {
        if(m < i)
            break;
        m -= i;
        if(n < ++ i)
            i = 1;
    }

    printf("%d\n", m);

    return 0;
}
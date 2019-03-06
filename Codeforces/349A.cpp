#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int i, j, k;
    int x;

    scanf("%d", &n);
    for(i = j = k = 0; i < n; i ++)
    {
        scanf("%d", &x);
        if(x == 25)
            ++ j;
        if(x == 50)
            if(j)
            {
                -- j;
                ++ k;
            }
            else
            {
                puts("NO");

                return 0;
            }
        if(x == 100)
            if(j && k)
            {
                -- j;
                -- k;
            }
            else
                if(j > 2)
                    j -= 3;
                else
                {
                    puts("NO");

                    return 0;
                }
    }

    puts("YES");

    return 0;
}
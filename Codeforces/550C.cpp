#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
using namespace std;

char s[N];

int main(void)
{
    int n;
    int i, j, k;
    int x;

    scanf("%s", s);
    n = strlen(s);

    for(i = 0; i < n; i ++)
        if(s[i] == '0' || s[i] == '8')
        {
            puts("YES");
            printf("%d\n", s[i] - '0');

            return 0;
        }

    for(i = 0; i + 1 < n; i ++)
        for(j = i + 1; j < n; j ++)
        {
            x = (s[i] - '0') * 10 + s[j] - '0';
            if(!(x % 8))
            {
                puts("YES");
                printf("%d\n", x);

                return 0;
            }
        }

    for(i = 0; i + 2 < n; i ++)
        for(j = i + 1; j + 1 < n; j ++)
            for(k = j + 1; k < n; k ++)
            {
                x = (s[i] - '0') * 100 + (s[j] - '0') * 10 + s[k] - '0';
                if(!(x % 8))
                {
                    puts("YES");
                    printf("%d\n", x);

                    return 0;
                }
            }

    puts("NO");

    return 0;
}
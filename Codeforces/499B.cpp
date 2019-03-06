#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define M 100020
#define L 12
using namespace std;

char x[M][L], y[M][L], s[L];
int a[M], b[M];

int main(void)
{
    int n, m;
    int i, j;

    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%s %s", x[i], y[i]);
        a[i] = strlen(x[i]);
        b[i] = strlen(y[i]);
    }

    for(i = 0; i < n; i ++)
    {
        scanf("%s", s);
        for(j = 0; j < m; j ++)
            if(!strcmp(s, x[j]))
            {
                if(i)
                    putchar(' ');
                printf("%s", a[j] <= b[j] ? s : y[j]);
            }
    }
    putchar('\n');

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1020
using namespace std;

char o[N][N];

int main(void)
{
    int n;
    int i, j;
    int c;

    scanf("%d", &n);

    for(i = c = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
        {
            o[i][j] = (i & 1) ^ (j & 1) ? '.' : 'C';
            c += o[i][j] == 'C';
        }
    
    printf("%d\n", c);
    for(i = 0; i < n; i ++)
        puts(o[i]);

    return 0;
}
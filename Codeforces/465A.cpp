#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
using namespace std;

char s[N];
int a[N], b[N];

int main(void)
{
    int n;
    int i;
    int o;

    scanf("%d", &n);
    scanf("%s", s);

    for(i = 0; i < n; i ++)
        a[i] = b[i] = s[i] - '0';
    for(++ b[0], i = 0; b[i] == 2; i ++)
    {
        b[i] = 0;
        ++ b[i + 1];
    }

    for(i = o = 0; i < n; i ++)
        o += a[i] != b[i];
    printf("%d\n", o);

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
using namespace std;

int t[N];

int main(void)
{
    int n;
    int i;
    int m, c;

    scanf("%d", &n);
    for(i = 1, m = 0, c = 0; i <= n; i ++)
    {
        scanf("%d", &t[i]);
        if(t[i] == t[m])
            ++ c;
        if(t[i]  < t[m] || !m)
        {
            m = i;
            c = 1;
        }
    }

    if(c == 1)
        printf("%d\n", m);
    else
        puts("Still Rozdil");

    return 0;
}
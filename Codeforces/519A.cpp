#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 8
using namespace std;

char s[N];
int v[1 << 8];

int main(void)
{
    int i, j;
    int w, b;

    v['Q'] = v['q'] = 9;
    v['R'] = v['r'] = 5;
    v['B'] = v['b'] = 3;
    v['N'] = v['n'] = 3;
    v['P'] = v['p'] = 1;

    for(i = w = b = 0; i < N; i ++)
    {
        scanf("%s", s);
        for(j = 0; j < N; j ++)
            if(isalpha(s[j]))
                (isupper(s[j]) ? w : b) += v[s[j]];
    }

    if(w == b)
        puts("Draw");
    else
        puts(w < b ? "Black" : "White");

    return 0;
}
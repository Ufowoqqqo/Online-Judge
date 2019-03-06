#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define L 1000020
using namespace std;

char s[L], t[L];

int main(void)
{
    int n;
    int i, j, k;
    vector<int> v;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%s", s);
        v.clear();
        for(j = 0; s[j]; j ++)
            if(isalpha(s[j]))
                v.push_back(j);
        if(v.size() == 2 && v.at(0) + 1 < v.at(1) && s[v.at(0)] == 'R' && s[v.at(1)] == 'C')
        {
            for(j = v.at(1) + 1, k = 0; s[j]; j ++)
                k = k * 10 + s[j] - '0';
            for(j = 0; k; (-- k) /= 26)
                t[j ++] = (k - 1) % 26 + 1;
            for(; j; putchar(t[-- j] + 'A' - 1))
                ;
            for(j = v.at(0) + 1; j < v.at(1); j ++)
                putchar(s[j]);
        }
        else
        {
            putchar('R');
            for(j = v.at(v.size() - 1) + 1; s[j]; j ++)
                putchar(s[j]);
            putchar('C');
            for(j = k = 0; j <= v.at(v.size() - 1); j ++)
                k = k * 26 + s[j] - 'A' + 1;
            printf("%d", k);
        }
        putchar('\n');
    }

    return 0;
}
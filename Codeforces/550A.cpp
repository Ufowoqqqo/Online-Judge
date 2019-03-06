#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define N 100020
using namespace std;

char s[N];
bool f[N];
vector<int> v;

int main(void)
{
    int c;
    int i;

    scanf("%s", s);
    for(i = c = 0; s[i + 1]; i ++)
    {
        if(s[i] == 'A' && s[i + 1] == 'B')
            v.push_back(i);
        if(s[i] == 'B' && s[i + 1] == 'A')
        {
            f[i] = true;
            ++ c;
        }
    }

    for(i = 0; i < (signed)v.size(); i ++)
        if(c - (v.at(i) && f[v.at(i) - 1]) - f[v.at(i) + 1])
        {
            puts("YES");

            return 0;
        }

    puts("NO");

    return 0;
}
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#define N 120
using namespace std;

char s[N];

int main(void)
{
    int n;
    set<char> t;
    int i;

    scanf("%d", &n);
    scanf("%s", s);

    t.clear();
    for(i = 0; i < n; i ++)
        t.insert(toupper(s[i]));
    puts((signed)t.size() == 26 ? "YES" : "NO");

    return 0;
}
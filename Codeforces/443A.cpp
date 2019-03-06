#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    set<int> s;
    char c;

    for(s.clear(); ~scanf("%c", &c); )
        if(isalpha(c))
            s.insert(c);

    printf("%d\n", s.size());

    return 0;
}
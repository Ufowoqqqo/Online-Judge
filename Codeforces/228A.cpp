#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    int a, b, c, d;
    set<int> s;

    scanf("%d %d %d %d", &a, &b, &c, &d);
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);

    printf("%d\n", 4 - (signed)s.size());

    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

bool check(const string &s)
{
    int i, j;

    for(i = 0, j = s.size() - 1; i < j; i ++, j --)
        if(s.at(i) != s.at(j))
            return false;

    return true;
}

int main(void)
{
    string s;
    int i, j;
    int u;
    string t, o;

    ios::sync_with_stdio(false);

    cin >> s;
    for(i = 0, u = 1 << s.size(), o = ""; i < u; i ++)
    {
        for(j = 0, t = ""; j < (signed)s.size(); j ++)
            if(i & (1 << j))
                t += s.at(j);
        if(check(t) && o < t)
            o = t;
    }

    cout << o << endl;

    return 0;
}
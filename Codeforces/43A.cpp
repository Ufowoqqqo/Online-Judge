#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    int n;
    int i;
    string s;
    map<string, int> m;
    map<string, int>::iterator x, y;

    ios::sync_with_stdio(false);

    cin >> n;
    for(i = 0; i < n; i ++)
    {
        cin >> s;
        ++ m[s];
    }

    x = y = m.begin();
    ++ y;
    cout << (x->second < y->second ? y->first : x->first) << endl;

    return 0;
}
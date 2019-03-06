#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    int n;
    int i;
    string s;
    map<string, int> t;

    ios::sync_with_stdio(false);

    cin >> n;
    t.clear();
    for(i = 0; i < n; i ++)
    {
        cin >> s;
        if(!t.count(s))
            cout << "OK" << endl;
        else
            cout << s << t[s] << endl;
        ++ t[s];
    }

    return 0;
}
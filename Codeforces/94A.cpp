#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

map<string, int> p;

int main(void)
{
    string s;
    string t;
    int i;

    ios::sync_with_stdio(false);

    cin >> s;
    for(i = 0; i < 10; i ++) {
        cin >> t;
        p[t] = i;
    }

    for(i = 0; i < 8; i ++) {
        cout << p[s.substr(i * 10, 10)];
    }

    return 0;
}

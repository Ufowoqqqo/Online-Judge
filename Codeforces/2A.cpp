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
    map<string, pair<int, int> > m;
    string s;
    int c, t;
    map<string, pair<int, int> >::iterator j;

    ios::sync_with_stdio(false);

    cin >> n;
    for(i = 0; i < n; i ++)
    {
        cin >> s >> c;
        if(m.count(s))
            c += m[s].first;
        m[s] = make_pair(c, i);
    }

    for(j = m.begin(), c = t = 0; j != m.end(); j ++)
        if(c < j->second.first || (c == j->second.first && j->second.second < t))
        {
            s = j->first;
            c = j->second.first;
            t = j->second.second;
        }
    cout << s << endl;

    return 0;
}
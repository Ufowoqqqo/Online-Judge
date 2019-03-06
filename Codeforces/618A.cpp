#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    int i;
    int t;
    vector<int> o;

    scanf("%d", &n);
    o.clear();
    for(i = 0; i < n; i ++)
    {
        o.push_back(1);
        while((signed)o.size() > 1 && o.at(o.size() - 2) == o.at(o.size() - 1))
        {
            t = o.at(o.size() - 1);
            o.pop_back();
            o.pop_back();
            o.push_back(t + 1);
        }
    }

    for(i = 0; i < (signed)o.size(); i ++)
        printf("%d ", o.at(i));

    return 0;
}
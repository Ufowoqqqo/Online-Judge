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
    vector<int> v;
    int i;
    int x;

    scanf("%d", &n);
    v.clear();
    for(i = 0; i < n; i ++) {
        scanf("%d", &x);
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    if((signed)v.size() == 1) {
        puts("NO");
    } else {
        printf("%d\n", v.at(1));
    }

    return 0;
}

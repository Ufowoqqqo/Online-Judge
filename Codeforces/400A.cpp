#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define N 20
using namespace std;

char s[N];

bool check(int k)
{
    int i, j;
    bool t;

    for(i = 0; i < k; i ++) {
        for(j = 0, t = true; j * k < 12 && t; j ++)
            if(s[j * k + i] == 'O') {
                t = false;
            }
        if(t) {
            return true;
        }
    }

    return false;
}

int main(void)
{
    int t;
    vector<int> o;
    int i;

    scanf("%d", &t);
    while(t --) {
        scanf("%s", s);

        o.clear();
        for(i = 12; i; i --)
            if(!(12 % i) && check(i)) {
                o.push_back(i);
            }

        printf("%d ", (signed)o.size());
        for(i = 0; i < (signed)o.size(); i ++) {
            printf("%dx%d ", 12 / o.at(i), o.at(i));
        }
        putchar('\n');
    }

    return 0;
}

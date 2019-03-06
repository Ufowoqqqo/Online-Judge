#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

char s[10][10];
int c[1 << 8];

int main(void)
{
    int k;
    int i, j;
    int m;

    scanf("%d", &k);
    for(i = 0; i < 4; i ++) {
        scanf("%s", s[i]);
        for(j = 0; j < 4; j ++) {
            ++ c[s[i][j]];
        }
    }

    for(i = '1', m = 0; i <= '9'; m = max(m, c[i ++]))
        ;

    puts((k << 1) < m ? "NO" : "YES");

    return 0;
}

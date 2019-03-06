#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 5020
using namespace std;

int a[N];

int main(void)
{
    int n, k;
    int i;

    scanf("%d %d", &n, &k);

    if(n < k) {
        puts("-1");

        return 0;
    }

    for(i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, greater<int>());

    printf("%d %d\n", a[k], a[k]);

    return 0;
}

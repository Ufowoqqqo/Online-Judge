#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);

    if(n <= 2) {
        puts("-1");
    } else
        for(i = n; i; i --) {
            printf("%d ", i);
        }

    return 0;
}

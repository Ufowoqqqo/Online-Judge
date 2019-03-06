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

    printf("%d ", n);
    for(i = 1; i < n; i ++) {
        printf("%d ", i);
    }

    return 0;
}

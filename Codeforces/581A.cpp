#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int a, b;

    scanf("%d %d", &a, &b);
    
    printf("%d %d\n", min(a, b), (max(a, b) - min(a, b)) >> 1);

    return 0;
}
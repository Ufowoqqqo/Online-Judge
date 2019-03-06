#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 5
using namespace std;

int c[N];

int main(void)
{
    int i;
    int s;

    for(i = s = 0; i < N; s += c[i ++])
        scanf("%d", &c[i]);
    
    printf("%d\n", !s || s % N ? -1 : s / N);

    return 0;
}
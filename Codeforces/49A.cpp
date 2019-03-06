#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 1000
using namespace std;

char s[N];

int main(void)
{
    int i;
    bool o;

    gets(s);

    for(i = 0; s[i]; i ++)
        if(isalpha(s[i]))
        {
            s[i] = tolower(s[i]);
            o = s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y';
        }

    puts(o ? "YES" : "NO");

    return 0;
}
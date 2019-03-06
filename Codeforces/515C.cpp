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
    long long a;
    vector<int> o;
    int i;

    scanf("%d", &n);
    scanf("%I64d", &a);

    o.clear();
    for(; n --; a /= 10)
        if(a % 10 > 1)
            if(a % 10 == 4)
            {
                o.push_back(3);
                o.push_back(2);
                o.push_back(2);
            }
            else
                if(a % 10 == 6)
                {
                    o.push_back(5);
                    o.push_back(3);
                }
                else
                    if(a % 10 == 8)
                    {
                        o.push_back(7);
                        o.push_back(2);
                        o.push_back(2);
                        o.push_back(2);
                    }
                    else
                        if(a % 10 == 9)
                        {
                            o.push_back(7);
                            o.push_back(3);
                            o.push_back(3);
                            o.push_back(2);
                        }
                        else
                            o.push_back(a % 10);

    sort(o.begin(), o.end(), greater<int>());
    for(i = 0; i < (signed)o.size(); i ++)
        putchar(o.at(i) + '0');

    return 0;
}
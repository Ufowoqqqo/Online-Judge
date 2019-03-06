#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
using namespace std;

int a[N], s[N];

int main(void)
{
	int n, t;
	int i;
	int o;

	scanf("%d %d", &n, &t);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}

	for(i = 1, o = 0; i <= n; i ++)
		o = max(o, (int)(upper_bound(s + i, s + n + 1, s[i - 1] + t) - s) - i);
	printf("%d\n", o);

	return 0;
}
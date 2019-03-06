#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 10000
using namespace std;

int a[N], b[N];

int main(void)
{
	int n;
	int i;
	int p, q;

	scanf("%d", &n);
	for(i = 1, p = 0; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		p |= a[i];
	}
	for(i = 1, q = 0; i <= n; i ++)
	{
		scanf("%d", &b[i]);
		q |= b[i];
	}

	printf("%d\n", p + q);

	return 0;
}
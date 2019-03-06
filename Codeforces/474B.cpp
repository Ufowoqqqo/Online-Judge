#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100020
#define M 100020
using namespace std;

int a[N], b[N], q[M];

int main(void)
{
	int n, m;
	int i;

	scanf("%d", &n);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		b[i] = b[i - 1] + a[i];
	}

	scanf("%d", &m);
	for(i = 1; i <= m; i ++)
	{
		scanf("%d", &q[i]);
		printf("%d\n", lower_bound(b + 1, b + n + 1, q[i]) - b);
	}

	return 0;
}
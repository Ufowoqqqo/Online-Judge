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
	int a, p, m;
	int o;

	scanf("%d", &n);
	for(i = o = 0, m = 101; i < n; i ++)
	{
		scanf("%d %d", &a, &p);
		m = min(m, p);
		o += a * m;
	}
	printf("%d\n", o);

	return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
	int n, p, k;
	int i;

	scanf("%d %d %d", &n, &p, &k);
	if(k + 1 < p)
		printf("<< ");
	for(i = p - k; i < p; i ++)
		if(i >= 1)
			printf("%d ", i);
	printf("(%d) ", p);
	for(i = p + 1; i <= p + k; i ++)
		if(i <= n)
			printf("%d ", i);
	if(p + k < n)
		printf(">>");

	return 0;
}
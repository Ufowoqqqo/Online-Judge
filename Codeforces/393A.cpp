#include <algorithm>
#include <cstdio>
#define N 120
using namespace std;

char s[N];
int c[1 << 8];

int main(void)
{
	int i;

	scanf("%s", s);
	for(i = 0; s[i]; i ++)
		++ c[s[i]];
	printf("%d\n", min(min(max(c['n'] - 1 >> 1, 0), c['i']), min(c['e'] / 3, c['t'])));

	return 0;
}
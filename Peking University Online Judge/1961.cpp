#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 2e6;

char s[MAXN];
int nxt[MAXN];

int main(void) {
	for (int N, kase = 1; ~scanf("%d", &N) && N; kase++) {
		scanf("%s", s + 1);
		printf("Test case #%d\n", kase); memset(nxt, 0, sizeof nxt);
		for (int i = 2, j = 0; i <= N; i++) {
			for (; j && s[i] != s[j + 1]; j = nxt[j]);
			if (s[i] == s[j + 1]) nxt[i] = ++j;
			if (nxt[i] && !(i % (i - nxt[i])) && i / (i - nxt[i]) > 1) printf("%d %d\n", i, i / (i - nxt[i]));
		}
		putchar('\n');
	}
	return 0;
}

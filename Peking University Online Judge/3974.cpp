#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXL = 2e6;
const int BASE = 31;

char s[MAXL];
unsigned long long h[2][MAXL], p[MAXL];

int main(void) {
	for (int kase = 1; ~scanf("%s", s + 1) && strcmp(s + 1, "END"); kase++) {
		printf("Case %d: ", kase); int n = strlen(s + 1); p[0] = 1LL;
		for (int i = 1; i <= n; i++) p[i] = p[i - 1] * BASE;
		for (int i = 1; i <= n; i++) h[0][i] = h[0][i - 1] * BASE + s[i] - 'a';
		for (int i = n; 1 <= i; i--) h[1][i] = h[1][i + 1] * BASE + s[i] - 'a';
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int l, r, m; //[l, r)
			
			for (l = 0, r = min(i, n - i + 1); l + 1 < r; ) {
				m = l + r >> 1;
				if (h[0][i - 1] - h[0][i - m - 1] * p[m] == h[1][i + 1] - h[1][i + m + 1] * p[m]) l = m; else r = m;
			}
			ans = max(ans, (l << 1) + 1);
			
			for (l = 0, r = min(i, n - i + 2); l + 1 < r; ) {
				m = l + r >> 1;
				if (h[0][i - 1] - h[0][i - m - 1] * p[m] == h[1][i] - h[1][i + m] * p[m]) l = m; else r = m;
			}
			ans = max(ans, l << 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
